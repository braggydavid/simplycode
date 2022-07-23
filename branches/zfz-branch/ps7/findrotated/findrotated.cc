#include <vector>


#include "findrotated.h"


using namespace std;

namespace 
{ // anonymous

int binary_search(const vector<int>& v, int l, int r, int x)
{
   while (l < r)
   {
       int m = (l + r) / 2;
       (v[m] < x) ? ++l : r = m;
   }

   return (v[r] == x) ? r : -1;
}

int locate(const vector<int>& v)
{
   int n = v.size()-1, l = 0, r = n;

   while (l < r)
   {
       int m = (l + r) / 2;
       (v[m] > v[n]) ? ++l : r = m;
   }
   return r;
}

} // anonymous



int findrotated(const vector<int>& v, int x)
{
   int n = v.size()-1, l = 0, r = n;

   int p = locate(v);
   (x > v[n]) ? r = p-1 : l = p;

   return binary_search(v, l, r, x);
}


