//***************************************************************************
// File name: 
// Author: 
// Date: 
// Class: 
// Assignment: 
// Purpose: 
//***************************************************************************
#define MEM_DEBUG#include "mem_debug.h"
#include "IntNode.h"
#include "Heap.h"


int main ()
{
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  IntNode *pcNode = new IntNode();
  Heap cHeap;

  std::cout << cHeap.size() << std::endl;

  cHeap.insert(pcNode);

  std::cout << cHeap.size() << std::endl;

  cHeap.insert(new IntNode());

  std::cout << cHeap.size() << std::endl;

  cHeap.deallocateItems();

  std::cout << cHeap.size() << std::endl;

	return EXIT_SUCCESS;
}