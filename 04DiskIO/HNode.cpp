#include "HNode.h"


std::ostream& operator<<(std::ostream &os, const HNode &theNode)
{
  theNode.outputNode(os);
  return os;
}