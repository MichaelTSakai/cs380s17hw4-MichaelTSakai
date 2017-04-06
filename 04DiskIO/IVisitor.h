#pragma once

#include "IntNode.h"
#include "DiskIONode.h"

class IVisitor
{
public:
  virtual void visit(IntNode &rcIntNode) = 0;
  virtual void visit(DiskIONode &rcDiskIONode) = 0;
};