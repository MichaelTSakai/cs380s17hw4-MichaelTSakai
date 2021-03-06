//***************************************************************************
// File name:	IntNode.h
// Author:		Michael Sakai
// Date:			03/21/2017
// Class:			CS380
// Assignment:Disk Scheduling
// Purpose:		This is a heap node that uses integer for it's key.
//**************************************************************************

#pragma once

#include "HNode.h"

class IntNode : public HNode
{
public:
  IntNode();
  IntNode(int key);

  bool operator< (ComparableItem const &right) const;
  bool operator> (ComparableItem  const &right) const;
  bool operator== (ComparableItem const  &right)const;

  virtual void changeKey(void*);

  virtual void outputNode(std::ostream& os) const;

  ~IntNode();

  virtual bool getKey(void*, int) const;
  
  virtual void acceptVisitor(IVisitor *pcVisitor);

  virtual bool updateKey(void*, int);
private: 
  int mKey;
};
