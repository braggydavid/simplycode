/* Given an arsorted array and a number n, find the first occurance of n in array, if do not find, then return the smallest p so that array[p] . n */
#include "findfirst.h"
#include <iostream>
#include <cassert>

int findfirst( std::vector<int>& v, int n)
{
    int l=0, r=v.size()-1;
    assert( v.size() > 0 );
    while( l != r )
    {
        int m=(l+r)/2;
        
        v[m] < n ? l = m+1 : r = m;
    }
    return v[r] == n ? r : -1;
    //return v[r] < n ? r+1 : r; 
}
