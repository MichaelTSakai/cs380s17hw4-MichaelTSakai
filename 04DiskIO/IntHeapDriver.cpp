//***************************************************************************
// File name:  IntHeapDriver.cpp
// Author:     Michael Sakai
// Date:       03/21/2017
// Class:      CS380
// Assignment: Disk Scheduling  
// Purpose:    Main driver for testing the intnode and heap
//***************************************************************************

#define MEM_DEBUG 1
#include "mem_debug.h"
#include "IntNode.h"
#include "Heap.h"
#include <fstream>

//********************************************************
// Function: main
//
// Description: main function for the IntHeapDriver
//
// Parameters:  none
//
// Returned:    0 if successful
//		
//********************************************************
int main ()
{
#ifdef MEM_DEBUG
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

  Heap cHeap, cHeapMIN;
  const HNode *pcReciever;
  HNode *pcExtracter;
  std::ifstream pFile;
  int receiver;
  const int ADD_NODE = 20;

  pFile.open("integerNode.txt");

  
  cHeapMIN.setSortDirection(Heap::MIN);

  while (pFile >> receiver)
  {
    cHeap.insert(new IntNode(receiver));
    cHeapMIN.insert(new IntNode(receiver));
  }
  
  std::cout << "*********\nMAX HEAP: \n*********\n";
  std::cout << "After Insert: " << cHeap;

  pcReciever = cHeap.heapExtreme();

  std::cout << std::endl << "Heap Extreme: " << *pcReciever;

  cHeap.insert(new IntNode(ADD_NODE));

  std::cout << std::endl << "Insert " << ADD_NODE << ": "
    << cHeap << std::endl;

  pcExtracter = cHeap.heapExtract();

  std::cout << "Extract: ";

  while (pcExtracter != nullptr)
  {
    std::cout << *pcExtracter << " ";
    delete pcExtracter;
    pcExtracter = cHeap.heapExtract();
  }

  std::cout << "\n\n*********\nMIN HEAP: \n*********\n";

  std::cout << "After Insert: " << cHeapMIN;

  pcReciever = cHeapMIN.heapExtreme();

  std::cout << std::endl << "Heap Extreme: " << *pcReciever;

  cHeapMIN.insert(new IntNode(ADD_NODE));

  std::cout << std::endl << "Insert " << ADD_NODE << ": "  
            << cHeapMIN << std::endl;

  pcExtracter = cHeapMIN.heapExtract();

  std::cout << "Extract: ";

  while (pcExtracter != nullptr)
  {
    std::cout << *pcExtracter << " ";
    delete pcExtracter;
    pcExtracter = cHeapMIN.heapExtract();
  }

  cHeap.deallocateItems();
  cHeapMIN.deallocateItems();

	return EXIT_SUCCESS;
}