#define MEM_DEBUG 1
#include "mem_debug.h"
#include "DiskIONode.h"
#include "Heap.h"
#include <fstream>

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
  pFile.open("init.dat");

  cHeap.setSortDirection(Heap::MIN);

  while (pFile >> ID)
  {
    pFile >> operation;
    pFile >> sector; 
    pFile >> track;
    
    cHeap.insert(new DiskIONode(0, abs(DEFAULT_TRACK - track), ID, operation,
      sector, track));
  }

  cHeap.buildHeap();

  std::cout << cHeap; 
}