#include <iostream>
#include <vector>
#include <cstdlib>
#include "combination.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "usage: combination arg1 arg2" << endl;
        exit(1);
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    cout << "icomb: " << endl;
    icomb(n, k);

    cout << "rcomb: " << endl;
    vector<int> v(k, -1);
    rcomb(v, n, k);
    
    return 0;
}
