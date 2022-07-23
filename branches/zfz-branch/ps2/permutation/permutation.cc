#include <iostream>

#include "print.h"
#include "permutation.h"

using namespace std;

namespace 
{ //anonymous

bool isvalid(const vector<int>& v, int k)
{
    for (int i = 0; i < k; ++i)
    {
        if (v[i] == v[k]) { return false; }
    }
    return true;
}

} //anonymous


void rpermu(vector<int>& v, int k)
{
    if (k <= 0) { Util::print(v); return; }
    
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        v[n-k] = i;
        if (isvalid(v, n-k)) { rpermu(v, k-1); }
    }
}


void rpermu(int n)
{
    vector<int> v(n, 0);
    rpermu(v, n);
}


void ipermu(int n)
{
    if (n <= 0) { return; }
    
    vector<int> v(n, -1);
    for (int r = 0; r >= 0; )
    {
        while (++v[r] < n && !isvalid(v, r));
        if (v[r] < n && r == n-1)
        {
            Util::print(v);
        }
        else
        {
            v[r] >= n? v[r--] = -1 : ++r;
        }
    }
}



