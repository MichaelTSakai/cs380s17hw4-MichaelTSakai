#include "Heap.h"

Heap::Heap()
{
  mHeapArray.push_back(nullptr);
  mSortDir = Direction::MAX;
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

  mHeapArray.clear();
}

void Heap::insert(HNode  *pcNode)
{
  mHeapArray.push_back(pcNode);
}

int Heap::size()
{
  return mHeapArray.size();
}

Heap::Direction Heap::getSortDirection()
{
  return mSortDir;
}

void Heap::setSortDirection(Heap::Direction dir)
{
  mSortDir = dir;
}

void Heap::buildHeap()
{

}

void Heap::heapify(int i)
{
  int left = leftNode(i);
  int right = rightNode(i);
  int largest = i;

  if (mHeapArray.size >= left)
  {
    if (needSwap(mHeapArray.at(i), mHeapArray.at(left)))
    {
      largest = left;
    }
  }
  else if(mHeapArray.size >= right)
  {
    if (needSwap(mHeapArray.at(i), mHeapArray.at(right)))
    {
      largest = right;
    }
  }

  if (largest != i)
  {
    
  }
}

int rightNode(int i)
{
  return i * 2 + 1;
}

int leftNode(int i)
{
  return i * 2;
}

bool Heap::needSwap(const ComparableItem *pParent, const ComparableItem *pChild)
{
  bool bSwap = false;
  switch (mSortDir)
  {
  case Direction::MAX: bSwap = *pParent < *pChild;
    break;
  case Direction::MIN: bSwap = *pParent > *pChild;
    break;
  }

  return bSwap;
}