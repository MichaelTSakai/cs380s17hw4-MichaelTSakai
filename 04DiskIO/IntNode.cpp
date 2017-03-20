#include "IntNode.h"


IntNode::~IntNode() 
{
}

bool IntNode::operator<(ComparableItem const &right) const
{
  return false;
}

bool IntNode::operator>(ComparableItem const &right) const
{
  return false;
}
bool IntNode::operator== (ComparableItem const  &right) const
{
  return false;
}

void IntNode::changeKey(void*)
{

}

void IntNode::outputNode(std::ostream& os) const
{

}

bool IntNode::getKey(void *, int) const
{
  return false;
}

bool IntNode::updateKey(void *, int) 
{
  return false;
}