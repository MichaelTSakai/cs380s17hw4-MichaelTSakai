#include "DiskIONode.h"
#include <iomanip>
#include "IVisitor.h"

DiskIONode::DiskIONode ()
{

}

DiskIONode::DiskIONode (int clock, int key, int id, char op, int sno, int tno) : IntNode::IntNode(key)
{
  mBirth = clock; 
  mID = id; 
  mOp = op; 
  mSNo = sno;
  mTNo = tno;
}

DiskIONode::~DiskIONode()
{

}

void DiskIONode::outputNode(std::ostream& os) const
{
  os << std::setw(6) << mID << std::setw(4) << mOp
    << std::setw(7) << mSNo << std::setw(6) << mTNo << std::endl;
}

void DiskIONode::updateDistance(int track)
{
  int distance = abs(track - mTNo);
  changeKey(&distance);
}

std::istream &operator >> (std::istream &is, DiskIONode &rcNode)
{
  int key;
  is >> rcNode.mBirth;
  is >> key;
  rcNode.updateKey(&key, sizeof(key));
  is >> rcNode.mID >> rcNode.mOp >> rcNode.mSNo >> rcNode.mTNo;

  return is;
}

//updateKey updates the key based on the current head track 

bool DiskIONode::updateKey(void* pCurrentTrack, int size)
{
  bool bSuccess;

  if (size == sizeof(int))
  {
    updateDistance(*static_cast<int*>(pCurrentTrack));
    bSuccess = true;
  }
  else
  {
    std::cerr << "Incorrect Data Size\n";
    bSuccess = false;
  }
  return bSuccess;
}

void DiskIONode::acceptVisitor(IVisitor *pcVisitor)
{
  pcVisitor->visit(*this);
}

bool DiskIONode::operator< (ComparableItem const &right) const
{
  bool bLessThan = false;
  int keyOrigin, keyRight;
  dynamic_cast<const DiskIONode*>(&right)->getKey(&keyRight, sizeof(int));
  getKey(&keyOrigin, sizeof(int));

  if (keyOrigin < keyRight)
  {
    bLessThan = true;
  }
  else if (keyOrigin == keyRight)
  {
    bLessThan = mBirth < dynamic_cast<const DiskIONode*>(&right)->mBirth;
  }

  return bLessThan;
}

bool DiskIONode::operator> (ComparableItem  const &right) const
{
  bool bGreaterThan = false;
  int keyOrigin, keyRight;
  dynamic_cast<const DiskIONode*>(&right)->getKey(&keyRight, sizeof(int));
  getKey(&keyOrigin, sizeof(int));

  if (keyOrigin > keyRight)
  {
    bGreaterThan = true;
  }
  else if (keyOrigin == keyRight)
  {
    bGreaterThan = mBirth > dynamic_cast<const DiskIONode*>(&right)->mBirth;
  }

  return bGreaterThan;
}