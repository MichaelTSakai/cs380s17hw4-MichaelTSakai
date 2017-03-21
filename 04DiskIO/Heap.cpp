#include "Heap.h"

int leftNode(int i);
int rightNode(int i);
int parentNode(int i);

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
  heapIncreaseKey(mHeapArray.size() - 1, pcNode);
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
  for (int i = mHeapArray.size() / 2; i > 0; i--)
  {
    heapify(i);
  }
}

void Heap::heapify(int i)
{
  int left = leftNode(i);
  int right = rightNode(i);
  int largest = i;
  int heapSize = mHeapArray.size() - 1;

  if (heapSize >= left)
  {
    if (needSwap(mHeapArray.at(i), mHeapArray.at(left)))
    {
      largest = left;
    }
  }
  if(heapSize >= right)
  {
    if (needSwap(mHeapArray.at(largest), mHeapArray.at(right)))
    {
      largest = right;
    }
  }

  if (largest != i)
  {
    std::iter_swap(&mHeapArray.at(i), &mHeapArray.at(largest));
    heapify(largest);
  }
}

HNode* Heap::heapExtract()
{
  int size = mHeapArray.size() - 1;
  HNode *pMax = mHeapArray.at(1);

  mHeapArray.at(1) = mHeapArray[size];
  mHeapArray.pop_back();

  heapify(1);

  return pMax;
}

void Heap::heapIncreaseKey(int size, HNode *pNode)
{
  if (*pNode < *mHeapArray.at(size))
  {
    std::cerr << "Error: key smaller than previous" << std::endl;
  }
  else
  {
    mHeapArray.at(size) = pNode;
    while (size > 1 && needSwap(mHeapArray[parentNode(size)], mHeapArray[size]))
    {
      std::iter_swap(&mHeapArray.at(parentNode(size)), &mHeapArray.at(size));
      size = parentNode(size);
    }
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

int parentNode(int i)
{
  return i / 2;
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

std::ostream& operator<<(std::ostream &os, const Heap &theHeap)
{
  for (int i = 1; i < theHeap.mHeapArray.size(); i++)
  {
    os << *theHeap.mHeapArray.at(i) << " ";
  }

  return os;
}