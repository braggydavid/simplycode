#include <stdexcept>
#include "intdiv.h"


using namespace std;

uint intdiv(uint x, uint y)
{
    if (y == 0) { throw runtime_error("divide by zero"); }
    if (x < y)  { return 0; }
    
    uint r = 1, t = y;
    while (x - t >= t) { r <<= 1; t <<= 1; }
    if ((x -= t) < y)  { return r; }

    uint l = 1, u = r;
    while(l < u)
    {
        uint m = (l + u) / 2;
        (x-y >= m*y) ? l = m+1 : u = m;
    }

    return r+l;
}


