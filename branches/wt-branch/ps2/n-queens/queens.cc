#include <vector>
#include <cstdlib>
#include "queens.h"
#include "print.h"

using namespace std;

bool isvalid(const vector<int> &p, int k)
{
    for (int i = 0; i < k; ++i)
    {
        if (abs(p[i]-p[k]) == abs(i-k) || p[i] == p[k]) { return false; }
    }
    return true;
}

void isolve(vector<int> &p, int &cnt)
{
    int k = 0, n = p.size();
    p[k] = 0;
    while (k >= 0)
    {
        ++p[k];
        while (p[k] <= n && !isvalid(p,k)) { ++p[k]; }
        if (p[k] <= n && k == n-1)
        {
            ++cnt; Util::print(p);
        }
        else 
        {
            p[k] > n ? --k : p[++k] = 0;
        }
    }
}

void rsolve(vector<int> &p, int k, int &cnt)
{
    int n = p.size();
    
    if (k == n) { ++cnt; Util::print(p); return; }
    for (int i = 0; i < n; ++i) 
    {
        p[k] = i+1;
        if (isvalid(p,k)) { rsolve(p,k+1,cnt); }
    }
}
