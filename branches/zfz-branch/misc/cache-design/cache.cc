#include "cache.h"

void Cache::put(int key, int val)
{
   if (ht.has(key))
   {
       int loc = ht.get(key);
       policy->insert(Node(key, val), loc);
   }
   else
   {
       if (policy->full())
       {
           Node* p = policy->exempt();
           ht.remove(p->getkey());
           policy->insert(Node(key, val), (int) p);
           ht.insert(key, (int) p);
       }
       else
       {
           ht.insert(key, policy->add(Node(key, val)));
       }
   }
}

int Cache::get(int key)
{

   if (ht.has(key))
   {
       int loc = ht.get(key);
       Node* node = policy->read(loc);
       return node->getval();
   }
   else
   {
       throw "key not in cache";

       // or do the following:
       // 1. read from memory
       // 2. put in to policy
       // 3. return the value
   }
}

void Cache::print()
{
   policy->print();
}
