#include <vector>
#include <algorithm>
#include <cassert>

#include "print.h"
#include "enumerate.h"

using namespace std;


void reverse(vector<int>& v, int b, int e)
{
    for (int i = b, j = e; i < j; ++i, --j)
    {
        swap(v[i], v[j]);
    }
}

bool isvalid(const vector<int>& v, int j, int x)
{
    for (int i = 0; i < j; ++i)
    {
        if ( v[i] == x ) { return false; }
    }
    return true;
}

void rpermu(vector<int>& p, int k)
{
    int n = p.size();
    if (k == n) { Util::print(p); return; }

    for (int i = 0; i < n; ++i)
    {
        p[k] = i;
        if (isvalid(p, k, p[k])) { rpermu(p, k+1); }
    }
}


void ipermu(int n) 
{
    assert(n > 0);
    
    vector<int> v(n, -1);

    int i = 0;
    while (i >= 0)
    {
        ++v[i];
        while (v[i] < n && !isvalid(v, i, v[i])) { ++v[i]; }

        if (v[i] < n && i == n-1) 
        { 
            Util::print(v);
        }
        else 
        {
            v[i] >= n ? --i : v[++i] = -1; 
        }
    }
}

void rpermu(int n)
{
    assert(n > 0);
    
    vector<int> v(n, -1);
    rpermu(v, 0);
}
