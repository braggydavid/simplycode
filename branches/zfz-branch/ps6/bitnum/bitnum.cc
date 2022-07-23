#include <iostream>
#include "bitnum.h"

using namespace std;


namespace 
{ //anonymous

bool test(uint x, uint i)
{
    return (x & (1 << i)) != 0;
}

// isone == 1 : get last bit 1 location;
// isone == 0 : get last bit 0 location.
uint last(uint x, uint start, bool isone)
{
    uint n = sizeof(uint) * 8;
    for (uint i = start; i < n; ++i)
    {
        if (test(x, i) == isone) { return i; }
    }
    return n;
}

void flip(uint& x, int pos)
{
    if (test(x, pos)) { x &= ~(1 << pos); }
    else              { x |=  (1 << pos); }
}

} //anonymous


bool bitnum(uint& x, bool isone)
{
    int n = sizeof(uint) * 8;

    uint b1 = last(x,  0,  isone);
    uint b2 = last(x, b1, !isone);

    if (b1 < n && b2 < n)
    {
        flip(x, b2);
        flip(x, b2-1);
        return true;
    }
    return false;
}
