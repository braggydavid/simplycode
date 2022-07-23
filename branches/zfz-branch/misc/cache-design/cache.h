#ifndef INCLUDED_CACHE
#define INCLUDED_CACHE

#include "policy.h"
#include "hashtable.h"

enum {MaxSize=1024};

class Cache
{
private:
   HashTable ht;
   Policy* policy;

public:

   Cache(Policy* p)
       : policy(p)
   {}
   ~Cache()
   {
       delete policy; policy = NULL;
   }

   void put(int key, int val);
   int  get(int key);
   void print();
};

#endif /* INCLUDED_CACHE */
