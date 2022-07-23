#ifndef INCLUDED_POLICY
#define INCLUDED_POLICY

#include "node.h"

class Policy
{
public:
   virtual void  insert(const Node& node, int loc) = 0;
   virtual int   add(const Node& node) = 0;
   virtual bool  full() = 0;
   virtual Node* exempt() = 0;
   virtual Node* read(int loc) = 0;
   virtual void  print() = 0;
};


#endif /* INCLUDED_POLICY */
