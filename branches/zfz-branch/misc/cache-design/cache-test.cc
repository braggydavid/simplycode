#include <iostream>
#include "cache.h"
#include "lru.h"

using namespace std;

int main(int argc, char *argv[])
{
   LRU lru(10);
   Cache cache(&lru);

   try
   {
       for (int i = 0; i < 15; ++i)
       {
           cache.put(i%10, i*10);
       }
       cache.print();

       for (int i = 0; i < 10; i+=3)
       {
           cout << "read key: "
                << i
                << ", value: "
                << cache.get(i)
                << endl;
       }

       cache.print();
   }
   catch (const char* e)
   {
       cout << e << endl;
   }

   return 0;
}
