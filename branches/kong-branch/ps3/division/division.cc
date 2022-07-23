/* 
Division of two numbers without using division operator
*/


#include "division.h"
#include <cassert>
#include <stdlib.h>
#include <stdexcept>

#include <iostream>
using namespace std;

uint uintdiv1( uint x, uint y )
{
    if (y == 0) { throw runtime_error("divide by 0"); }
    if ( x < y ) return 0;

    uint rt = 1, t = y;
    while ( x - t >= t ) { rt <<= 1; t  <<= 1; }
    return rt + uintdiv1( x - t, y );
}

uint uintdiv2(uint x, uint y)
{
    if (y == 0) { throw runtime_error("divide by 0"); }
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

// @FIXME there is overflow problem when y is very big, 
uint uintdiv3( uint x, uint y)
{
    if (y == 0) { throw runtime_error("divide by 0"); }
    if (x < y)  { return 0; }

    uint rt=0;
    uint bit = 1, tbig = x, tsmall = y;
    while ( tbig > tsmall && tbig - tsmall >= tsmall )
    {
        tbig >>= bit;
        tsmall <<=bit;
        bit *= 2;
        std::cerr << bit  << " " << tbig << " " << tsmall << std::endl;
    }
    cout << "bit= " << bit << std::endl;

    uint br = 1 << ( 2 * bit - 1 ), bl = 1 ;
    while (bl < br)
    {
        uint m = (br+bl)/2;
        std::cerr << ">> " << y*m  << "          " <<  x-y << std::endl;
        x - y >= y * m ? bl = m+1 : br = m;
        std::cerr << bl << " " << br << std::endl;
    }
    return rt + bl;
}




