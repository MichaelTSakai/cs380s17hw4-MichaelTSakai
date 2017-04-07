//***************************************************************************
// File name:	DiskIONode.h
// Author:		Michael Sakai
// Date:			04/6/2017
// Class:			CS380
// Assignment:Disk Scheduling
// Purpose:		This is a heap node that uses the distance from the node's track
//						to the head's track. 
//**************************************************************************

#pragma once

#include "IntNode.h"

class DiskIONode : public IntNode
{

public:

  DiskIONode();

  DiskIONode(int clock) { mBirth = clock; };

  DiskIONode(int clock, int key, int id, char op, int sno, int tno);

  virtual ~DiskIONode();


  // Function to output the contents of the Node. This will be called
  // by the function displayHeap in the class MaxHeap

  virtual void outputNode(std::ostream& os) const;

  void updateDistance(int track);

  friend std::istream& operator >> (std::istream& is, DiskIONode &node);

  int getTrackNumber() const { return mTNo; };

  int getBirth() const { return mBirth; };

  void acceptVisitor(IVisitor *pcVisitor);

  // we want to turn the Max heap into a min heap, so
  // flip the result of the < and > operators.
  virtual bool operator< (ComparableItem const &right) const;
  virtual bool operator> (ComparableItem  const &right) const;

  virtual bool updateKey(void*, int);


private:
  int mID;
  char mOp;
  int mSNo;
  int mTNo;
  int mBirth;
};
