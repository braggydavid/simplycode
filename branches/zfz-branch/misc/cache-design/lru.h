#ifndef INCLUDED_LRU
#define INCLUDED_LRU


#include "policy.h"

enum {MaxCacheSize=1024};

class LRU : public Policy
{
private:
   Node* mem;
   Node* head;
   Node* tail;
   int   size;
   int   max_size;
   void adjust(Node* curr);

public:

   LRU(int n=MaxCacheSize)
       :size(0), max_size(n), head(0), tail(0)
   {
       mem = new Node[n];
   }

   ~LRU()
   {
       size = max_size = 0;
       head = tail = 0;
       delete [] mem;
   }

   virtual void  insert(const Node& node, int loc);
   virtual int   add(const Node& node);
   virtual bool  full();
   virtual Node* exempt();
   virtual Node* read(int loc);
   virtual void  print();
};

#endif /* INCLUDED_LRU */
