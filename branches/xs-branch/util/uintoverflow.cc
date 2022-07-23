#include "uintoverflow.h"
#include <stdexcept>
#include <climits>


namespace Util
{

using namespace std;

uint adduint(uint a, uint b)
{
    if (ULONG_MAX - a < b)
    {
        throw runtime_error("uint overflow");
    }
    
    return a + b;
}

uint multuint(uint a, uint b)
{
    if (a == 0 || b == 0) { return 0; }

    uint s = a, x = 1;
    while (b - x >= x)
    {
        s = adduint(s,s); x += x;
    }
    
    return adduint(s, multuint(a, b-x)); 
}

uint multuint1(uint a, uint b)
{
    if (a == 0 || b == 0) { return 0; }
    
    uint s = 0, i = 0;
    while(i++ < a) { s = adduint(s, b); }
    
    return s;
}

}
