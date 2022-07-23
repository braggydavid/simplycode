#include "bitop.h"

uint rbitadd(uint a, uint b)
{
    if (b == 0) { return a; }

    uint carry = (a & b) << 1;
    
    return rbitadd(a^b, carry);
}

uint ibitadd(uint a, uint b)
{
    while (b > 0)
    {    
        uint c = (a & b) << 1;    
        a = a^b; b = c;
    }
    
    return a;
}

uint bitminus(uint a, uint b)
{
    return ibitadd(a, ibitadd(~b, 1));
}

uint bitmulti(uint a, uint b)
{
    if (a < b) { return bitmulti(b, a); }

    uint r = 0, p = 1, i = 0;
    while (b > 0)
    {
        if (p & b) 
        { 
            r = ibitadd(r, a << i);
            b = b & (~p);
        }
        p = p << 1; ++i;
    }
    return r;
}

uint rbitdiv(uint a, uint b)
{
    if (b == 0) { throw "divide-by-zero"; }
    if (a < b)  { return 0; }

    return ibitadd(1, rbitdiv(bitminus(a, b), b));
}
