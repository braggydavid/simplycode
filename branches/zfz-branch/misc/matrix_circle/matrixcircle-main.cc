#include <iostream>
#include <cstdlib>
#include "matrixcircle.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3) { return 1; }
    
    int r = atoi(argv[1]);
    int c = atoi(argv[2]);

    int** m = init(r, c);
    print(m, r, c);
    cout << "circle print: ";
    print_circle(m, r, c);
    
    return 0;
}
