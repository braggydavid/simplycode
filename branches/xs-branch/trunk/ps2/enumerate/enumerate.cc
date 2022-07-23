#include <vector>
#include <algorithm>
#include <cassert>

#include "print.h"
#include "enumerate.h"

using namespace std;

void renum(vector<int>& p, int k)
{
    int n = p.size();
    if (k >= n) { Util::print(p); return; }

    for (int i = 0; i < n; ++i)
    {
        p[k] = i;
        renum(p, k+1); 
    }
}


void ienum(int n) 
{
    assert(n > 0);
    
    vector<int> v(n, -1);

    for (int i = 0; i >= 0; )
    {
        ++v[i];

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

void renum(int n)
{
    assert(n > 0);
    
    vector<int> v(n, -1);
    renum(v, 0);
}
