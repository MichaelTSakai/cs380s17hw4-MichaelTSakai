//********************************************************
// File name:  DiskIONode.cpp
// Author:     Michael Sakai
// Date:       4/6/2017
// Class:      CS380
// Assignment: Disk Scheduling
// Purpose:    Defines header file IntNode.h
//********************************************************

#include "DiskIONode.h"
#include <iomanip>
#include "IVisitor.h"

//********************************************************
// Constructor: DiskIONode
//
// Description: Initialize data members.
//
// Parameters:  none
//
// Returned:    none
//		
//********************************************************
DiskIONode::DiskIONode ()
{

}

//********************************************************
// Constructor: DiskIONode
//
// Description: Initialize data members.
//
// Parameters:  clock - current time
//							key		- key of the node
//							id		- ID of the node
//							op		- Operation (R/W)
//							sno		- Sector number
//							tno		- Track number
//
// Returned:    none
//		
//********************************************************
DiskIONode::DiskIONode (int clock, int key, int id, char op, int sno, int tno) 
												: IntNode::IntNode(key)
{
  mBirth = clock; 
  mID = id; 
  mOp = op; 
  mSNo = sno;
  mTNo = tno;
}

//********************************************************
// Destructor: ~DiskIONode
//
// Description: Destroys all data member
//
// Parameters:  none
//
// Returned:    none
//		
//********************************************************
DiskIONode::~DiskIONode()
{

}

//********************************************************
// Function: outputNode
//
// Description: outputs the key value to the ostream
//
// Parameters:  os - the ostream where the output will be sent
//
// Returned:    none
//		
//********************************************************
void DiskIONode::outputNode(std::ostream& os) const
{
	const int BUFFER_ID = 3, BUFFER_OPERATION = 4, BUFFER_SECTOR = 7,
		BUFFER_TRACK = 6;

  os << std::setw(BUFFER_ID) << mID << std::setw(BUFFER_OPERATION) << mOp
    << std::setw(BUFFER_SECTOR) << mSNo << std::setw(BUFFER_TRACK) << mTNo;
}

//********************************************************
// Function: updateKey
//
// Description: Updates the distance between the current head 
//							and the node track.
//
// Parameters:  track - track of the head
//
// Returned:    none
//		
//********************************************************
void DiskIONode::updateDistance(int track)
{
  int distance = abs(track - mTNo);
  changeKey(&distance);
}

//********************************************************
// Function: operator >>
//
// Description: input operator. 
//
// Parameters:  is		 - input stream
//							rcNode - where the data is stored
//
// Returned:    is - updated stream
//		
//********************************************************
std::istream &operator >> (std::istream &is, DiskIONode &rcNode)
{
  int key;
  is >> rcNode.mBirth;
  is >> key;
  rcNode.updateKey(&key, sizeof(key));
  is >> rcNode.mID >> rcNode.mOp >> rcNode.mSNo >> rcNode.mTNo;

  return is;
}

//********************************************************
// Function: updateKey
//
// Description: Updates keys based off of the head's current 
//							track
//
// Parameters:  pCurrentTrack - current track 
//							size					- size of pCurrentTrack
//
// Returned:    false if error
//		
//********************************************************
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

//********************************************************
// Function: acceptVisitor
//
// Description: accepts the visitor class and passes itself
//							into the parameter of visit
//
// Parameters:  pcVisitor - the visitor class
//
// Returned:    none
//		
//********************************************************
void DiskIONode::acceptVisitor(IVisitor *pcVisitor)
{
  pcVisitor->visit(*this);
}

//********************************************************
// Function: operator<
//
// Description: overloads < operator. Compares the key 
//              of the two object
//
// Parameters:  cRight - the right object
//
// Returned:    true of left object < right object
//		
//********************************************************
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

//********************************************************
// Function: operator>
//
// Description: overloads > operator. Compares the key 
//              of the two object
//
// Parameters:  cRight - the right object
//
// Returned:    true of left object > right object
//		
//********************************************************
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