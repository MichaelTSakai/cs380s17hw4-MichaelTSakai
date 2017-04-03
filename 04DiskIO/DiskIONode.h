#pragma once

#include "IntNode.h"

class DiskIONode : public IntNode
{
  void changeKey(void*);
  void outputNode(std::ostream& os) const; 

  bool getKey(void*, int);
  
  bool updateKey(void*, int);
private:
  int mSector; 
  int mID; 
  int mTrack; 
  char mAccessType; 
};