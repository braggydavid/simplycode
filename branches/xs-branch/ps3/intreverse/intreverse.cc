#include "intreverse.h"
#include "uintoverflow.h"

#include <iostream>
using namespace std;

int intreverse(int x)
{
    return x < 0 ? -uintreverse(-x) : uintreverse(x);
}

uint uintreverse(uint x)
{
    uint r = 0;
    while (x > 0)
    {
        r = Util::adduint(Util::multuint(r,10), x%10);
        x = x / 10;
    }

    return r;
}


uint binaryreverse(uint x)
{
    uint r = 0;
    while (x > 0)
    {
        r = (r << 1) + (x & 1);
        x = x >> 1;
    }

    return r;    
}
