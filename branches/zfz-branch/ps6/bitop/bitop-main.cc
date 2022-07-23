#include <iostream>
#include <cstdlib>

#include "bitop.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "usage: bitop arg1 arg2" << endl;
        exit(1);
    }
    
    uint a = atoi(argv[1]);
    uint b = atoi(argv[2]);
        
    cout << rbitadd(a, b) << endl;
    cout << ibitadd(a, b) << endl;
    cout << (int) bitminus(a, b) << endl;
    cout << bitmulti(a, b) << endl;
    //cout << bitmulti1(a, b) << endl;
    cout << rbitdiv(a, b) << endl;
    return 0;
}
