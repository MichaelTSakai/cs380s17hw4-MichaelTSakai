//***************************************************************************
// File name:  DiskHeapDriver.cpp
// Author:     Michael Sakai
// Date:       03/21/2017
// Class:      CS380
// Assignment: Disk Scheduling  
// Purpose:    Main driver for testing the disk driver
//***************************************************************************

#define MEM_DEBUG 1
#include "mem_debug.h"
#include "DiskIONode.h"
#include "Heap.h"
#include <fstream>

const int BUFFER_ID = 3, BUFFER_OPERATION = 4, BUFFER_SECTOR = 7,
BUFFER_TRACK = 6, BUFFER_TRACK_CROSSED = 17,
BUFFER_WAIT = 11;


void feedHeap(Heap &rcHeap, std::ifstream &rcFile);
void initializeHeap(Heap &rcHeap, std::ifstream &rcFile);

//********************************************************
// Function: main
//
// Description: main function for the DiskHeapDriver
//
// Parameters:  none
//
// Returned:    0 if successful
//		
//********************************************************
int main()
{
#ifdef MEM_DEBUG
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  Heap cHeap;
  int ID, sector, track;
  const int DEFAULT_BIRTH = 0, DEFAULT_TRACK = 0;
  char operation;

  std::ifstream pFile;

	initializeHeap(cHeap, pFile);

	std::cout << std::setw(BUFFER_ID) << "ID#" 
		<< std::setw(BUFFER_OPERATION) << "R/W"
		<< std::setw(BUFFER_SECTOR) << "Sector" 
		<< std::setw(BUFFER_TRACK) << "Track" << std::setw(BUFFER_TRACK_CROSSED)
		<< "Tracks Crossed" << std::setw(BUFFER_WAIT) << "Wait Time" << std::endl;

	std::cout << std::setw(BUFFER_ID) << "---" 
		<< std::setw(BUFFER_OPERATION) << "---"
		<< std::setw(BUFFER_SECTOR) << "------" 
		<< std::setw(BUFFER_TRACK) << "-----" << std::setw(BUFFER_TRACK_CROSSED)
		<< "--------------" << std::setw(BUFFER_WAIT) << "---------" << std::endl;

	feedHeap(cHeap, pFile);

	cHeap.deallocateItems();
}

//********************************************************
// Function: initializeHeap
//
// Description: initializes the heap
//
// Parameters:  rcHeap - heap that needs to be initialized
//							pFile	 - file the data is taken from
//
// Returned:    none
//		
//********************************************************
void initializeHeap(Heap &rcHeap, std::ifstream &pFile)
{
	int ID, sector, track;
	const int DEFAULT_BIRTH = 0, DEFAULT_TRACK = 0;
	char operation;
	pFile.open("init.dat");

	rcHeap.setSortDirection(Heap::MIN);

	while (pFile >> ID)
	{
		pFile >> operation;
		pFile >> sector;
		pFile >> track;

		rcHeap.insert(new DiskIONode(DEFAULT_BIRTH, abs(DEFAULT_TRACK - track), ID, operation,
			sector, track));
	}

	pFile.close();
}

//********************************************************
// Function: feedHeap
//
// Description: feeds the heap with additional data and goes through
//							the disk schedule.
//
// Parameters:  rcHeap - heap that holds the data
//							pFile	 - file the data is taken from
//
// Returned:    none
//		
//********************************************************
void feedHeap(Heap &rcHeap, std::ifstream &pFile)
{
	int ID, sector, track;
	int currentTrack = 0, trackCrossed;
	int clock = 0;
	char operation;
	const int ARRAY_BUFFER = 1;

	pFile.open("diskio.dat");

	while (rcHeap.size() > ARRAY_BUFFER)
	{
		if (!pFile.eof())
		{
			pFile >> ID;
			pFile >> operation;
			pFile >> sector;
			pFile >> track;

		rcHeap.insert(new DiskIONode(clock, abs(currentTrack - track), ID, operation,
			sector, track));
		}

		rcHeap.buildHeap();

		std::cout << *rcHeap.heapExtreme();

		trackCrossed = abs(currentTrack - 
		dynamic_cast<const DiskIONode*>(rcHeap.heapExtreme())->getTrackNumber());

		std::cout << std::setw(BUFFER_TRACK_CROSSED) << trackCrossed;
		std::cout << std::setw(BUFFER_WAIT)
			<< clock - dynamic_cast<const DiskIONode*>(rcHeap.heapExtreme())->getBirth() 
			<< std::endl;

		currentTrack = 
		dynamic_cast<const DiskIONode*>(rcHeap.heapExtreme())->getTrackNumber();

		delete dynamic_cast<DiskIONode*>(rcHeap.heapExtract());

		rcHeap.updateEachKey(&currentTrack, sizeof(currentTrack));

		clock++;
	}

	pFile.close();
}