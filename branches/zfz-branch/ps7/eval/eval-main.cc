#include <sstream>
#include <iostream>
#include <stdexcept>

#include "eval.h"


using namespace std;


int main(int argc, char *argv[])
{
   string line;
   while (getline(cin, line))
   {
       cout << line << endl;
       queue<int> e;
       stringstream ss(line);

       int var; char op;
       while (ss >> var)
       {
           e.push(var);
           if (ss >> op) { e.push((int)op); }
       }

       try
       {
           cout << eval(e) << endl;
       }
       catch (const char* e)
       {
           cout << e << endl;
       }
   }
   return 0;
}
