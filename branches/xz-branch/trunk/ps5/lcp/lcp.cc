#include <algorithm>
#include "lcp.h"

using namespace std;
using namespace DS;

int lcp(TNode* t, int x, int y, TNode** p)
{
   if (!t) { return 0; }

   int r = 0;
   if (t->value == x) { ++r; }
   if (t->value == y) { ++r; }

   if (r < 2) { r += lcp(t->lt, x, y, p); }
   if (r < 2) { r += lcp(t->rt, x, y, p); }

   if (r == 2 && *p == NULL) { *p = t;}

   return r;
}

void rbst_lcp(TNode* t, int x, int y, TNode** p)
{
   if (!t) { return; }

   if (x < y) { swap(x, y); }

   if (t->value >= y && t->value <= x)
   {
       *p = t; return;
   }

   t = (t->value > x) ? t->lt : t->rt;
   rbst_lcp(t, x, y, p);
}

void ibst_lcp(TNode* t, int x, int y, TNode** p)
{
   if (x < y) { swap(x, y); }

   while (t)
   {
       if (t->value >= y && t->value <= x)
       {
           *p = t; break;
       }

       t = (t->value > x) ? t->lt : t->rt;
   }
}
