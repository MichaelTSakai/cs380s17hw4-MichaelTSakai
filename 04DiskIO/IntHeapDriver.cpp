//***************************************************************************
// File name: 
// Author: 
// Date: 
// Class: 
// Assignment: 
// Purpose: 
//***************************************************************************

#define MEM_DEBUG 1
#include "mem_debug.h"
#include "IntNode.h"
#include "Heap.h"
#include <fstream>


int main ()
{
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  Heap cHeap;
  std::ifstream pFile;
  int receiver;

  pFile.open("integerNode.txt");

  while (pFile >> receiver)
  {
    cHeap.insert(new IntNode(receiver));
  }
  
  std::cout << cHeap;

  cHeap.setSortDirection(Heap::MIN);

  cHeap.buildHeap();

  std::cout << std::endl << cHeap;


	return EXIT_SUCCESS;
}