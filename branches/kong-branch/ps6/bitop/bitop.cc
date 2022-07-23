/* Using bit operation to implement add/minus/divide/multiply operations. */
#include "bitop.h"
typedef unsigned long ulong;

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
        a ^= b; 
        b = c;
    }
    return a;
}

uint bitminus( uint a, uint b )
{
    return ibitadd( a, ibitadd(~b, 1) );
}

uint bitmulti( uint a, uint b )
{
    if ( a == 0 || b == 0 ) return 0;

    uint r=0, p=1, i=0;
    while ( p != 0 )
    {
        if ( p & b )
        {
            r = ibitadd(r, a << i);
        }
        p <<= 1; ++i;
    }
    return r;
}

uint rbitdiv( uint a, uint b)
{
    // may be we can do something like what we have done for ps3->division
    if ( b == 0 ) { throw "Divided by 0"; }
    if ( a < b ) { return 0; }

    return ibitadd( 1, rbitdiv( bitminus(a, b), b ));
}



