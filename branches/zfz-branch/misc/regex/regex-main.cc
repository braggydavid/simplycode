#include <iostream>
#include <stdexcept>

#include "regex.h"

using namespace std;


int main(int argc, char *argv[])
{
   string str, pat;
   while (getline(cin, str) && getline(cin, pat))
   {
       cout << str << endl;
       cout << pat << endl;
       try
       {
           if (ismatch(str, pat))
           {
               cout << "yes" << endl;
           }
           else
           {
               cout << "no" << endl;
           }
       }
       catch (const runtime_error& e)
       {
           cout << e.what() << endl;
       }
   }

   return 0;
}
