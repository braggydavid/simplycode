#include <cmath>
#include <vector>
#include "intersect.h"


using namespace std;

namespace 
{
    bool has(const vector<int>& a, int x)
    {
        int l = 0, r = a.size() - 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            (a[m] < x) ? l = m + 1 : r = m;
        }
        return (a[l] == x) ? true : false;
    }

    void uniadd(vector<int>* v, int x)
    {
        if (!v) { return; }
        if (v->empty() || v->back() != x)
        {
            v->push_back(x);
        }
    }
    
    //double log2(double x)
    //{
    //    return log(x) / log(2.0);
    //}
}

vector<int> intersect(const vector<int>& a, const vector<int>& b)
{
    double n = (double) (b.size());
    
    // Make sure that a.size() <= b.size();
    if (a.size() > n) { return intersect(b, a); }

    int x = log2(n) - 1;
    
    return (x > 0 && a.size() < n/x) ? intersect2(a,b) : intersect1(a,b);
}

vector<int> unify(const vector<int>& a, const vector<int>& b)
{
    vector<int> r;
    int i = 0, j = 0, x = 0;
    
    while (i < a.size() && j < b.size())
    {
        x = (a[i] < b[j]) ? a[i++] : b[j++];
        uniadd(&r, x);
    }

    while (i < a.size()) { uniadd(&r, a[i++]); }
    while (j < b.size()) { uniadd(&r, b[j++]); }
    
    return r;
}

vector<int> substract(const vector<int>& a, const vector<int>& b)
{
    double n = (double) (b.size());
    int x = log2(n) - 1;
    
    return (x > 0 && a.size() < n/x) ? minus2(a,b) : minus1(a,b);
}


vector<int> intersect1(const vector<int>& a, const vector<int>& b)
{
    vector<int> r;
    int i = 0, j = 0;
    
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            uniadd(&r, a[i]);
            ++i; ++j;
        }
        else
        {
            a[i] < b[j] ? ++i : ++j;
        }
    }
    
    return r;
}

vector<int> intersect2(const vector<int>& a, const vector<int>& b)
{
    vector<int> r;
    
    for (int i = 0; i < a.size(); ++i)
    {
        if (!has(b, a[i])) { continue; }

        uniadd(&r, a[i]);
    }
    return r;
}


vector<int> minus1(const vector<int>& a, const vector<int>& b)
{
    vector<int> r;
    int i = 0, j = 0;
    
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            r.push_back(a[i++]);
        }
        else
        {
            if (a[i] == b[j++]) { ++i; }
        }
    }
    
    while (i < a.size()) { r.push_back(a[i++]); }
    
    return r;
}

vector<int> minus2(const vector<int>& a, const vector<int>& b)
{
    vector<int> r;
    for (int i = 0; i < a.size(); ++i)
    {
        if (!has(b, a[i])) { r.push_back(a[i]); }
    }
    return r;
}
