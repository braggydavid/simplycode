#include "xcessor.h"

using namespace DS;

TNode* successor(TNode* t, int val)
{
   TNode* p = NULL;

   while (t)
   {
       if (t->value <= val)
       {
           t = t->rt;
       }
       else
       {
           p = t; t = t->lt;
       }
   }

   return p;
}

TNode* predecessor(TNode* t, int val)
{
   TNode* p = NULL;

   while (t)
   {
       if (t->value < val)
       {
           p = t; t = t->rt;
       }
       else
       {
           t = t->lt;
       }
   }
   return p;
}
