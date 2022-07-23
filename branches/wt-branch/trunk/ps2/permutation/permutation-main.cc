#include <iostream>
#include <cstdlib>
#include "permutation.h"


using namespace std;

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3, 4};
    
    int len = sizeof(a) / sizeof(a[0]);
    
    for (int i = 0; i < len; ++i)
    {
        cout << "iteratively: " << endl;
        ipermu(a[i]);
        
        cout << "recursively: " << endl;
        rpermu(a[i]);
        
        cout << "---" << endl;
    } 
    
   return 0;
}

