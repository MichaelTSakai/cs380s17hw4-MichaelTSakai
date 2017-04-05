#include "DiskIONode.h"

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


void DiskIONode::outputNode(std::ostream& os) const
{
  
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
  rcNode.changeKey(&key);
  is >> rcNode.mID >> rcNode.mOp >> rcNode.mSNo >> rcNode.mTNo;
}

bool DiskIONode::updateKey(void*, int)
{
  return false;
}