#include <iostream>
#include <cstdlib>

#include "findrotated.h"

using namespace std;


int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   int x = atoi(argv[2]);

   vector<int> v;
   for (int i = 0; i < 10; ++i)
   {
       v.push_back((i+n)%10);
       cout << v[i] << " ";
   }
   cout << endl;

   cout << "x = " << x << endl;
   cout << findrotated(v, x) << endl;

   return 0;
}
