#include "Heap.h"

Heap::Heap()
{
  mHeapArray.push_back(nullptr);
}

Heap::~Heap()
{

}

void Heap::deallocateItems()
{
  std::vector<HNode*>::iterator iterator;

  iterator = mHeapArray.begin();

  while (iterator != mHeapArray.end())
  {
    delete *iterator;
    iterator++;
  }
}

void Heap::insert(HNode  *pcNode)
{
  mHeapArray.push_back(pcNode);
}

int Heap::size()
{
  return mHeapArray.size();
}