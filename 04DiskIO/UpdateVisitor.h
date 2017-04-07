//***************************************************************************
// File name:	UpdateVisitor.h
// Author:		Michael Sakai
// Date:			04/6/2017
// Class:			CS380
// Assignment:Disk Scheduling
// Purpose:		Visitor class that visits and calls the class's update function
//**************************************************************************
#pragma once

#include "IVisitor.h"

class UpdateVisitor : public IVisitor
{
public:
  UpdateVisitor(void*, int);
  void visit(IntNode &rcIntNode);
  void visit(DiskIONode &rcDiskIONode);
private:
  void *pmBuffer;
  int mSize;
};