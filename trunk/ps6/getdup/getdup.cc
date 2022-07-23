#include "getdup.h"

using namespace std;


bool hasdup(const vector<int>& v)
{
    vector<int> t(v.size(), 0);
    
    for (int i = 0; i < v.size(); ++i)
    {
        int e = v[i];
        if (t[e]++ > 0) { return true; }
    }
    
    return false;
}

int getdup(const vector<int>& v)
{
    int x = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        x ^= v[i]; 
    }
    for (int i = 0; i < v.size()-1; ++i)
    {
        x ^= i;
    }
    return x;
}

int getonedup(const vector<int>& v)
{
    int n = v.size();
    int p = n-1, q = n-1;
    do
    {
        p = v[p]; p = v[p]; q = v[q];
    } while (p != q);
    
    p = n-1;
    while (p != q)
    {
        p = v[p]; q = v[q];
    }
    
    return p;
}
