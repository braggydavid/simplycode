#include <algorithm>
#include "unipermu.h"
#include "print.h"


using namespace std;

namespace { // anonymous

void getstat(const vector<int>& a, map<int, int>& m)
{
    int i = 0;
    while (i < a.size()) { ++m[a[i++]]; }
}

bool isvalid(const map<int, int>& m, const vector<int>& r, int k)
{
    int cnt = 1;
    //for (int i = r.size()-1; i > k; --i)
    for (int i = 0; i < k; ++i)
    {
        if (r[i] == r[k]) { ++cnt; }
    }

    map<int, int>::const_iterator it = m.find(r[k]);
    return (cnt > it->second) ? false : true;
}

void reverse(vector<int>& v, int s, int e)
{
    while (s < e) { swap(v[s++], v[e--]); }
}

} // anonymous




// major algorithm for permuation.
void runipermu(const map<int, int>& m, vector<int>& r, int k)
{
    if (k >= r.size()) { Util::print(r); return; }

    map<int, int>::const_iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr)
    {
        r[k] = itr->first;
        if (isvalid(m, r, k)) { runipermu(m, r, k+1); }
    }
}

bool nextpermu(vector<int>& v)
{
    int p = v.size() - 2;
    while (p >= 0 && v[p] >= v[p+1]) { --p; }

    if (p < 0) { return false; }

    int t = p+1; 
    while (t < v.size() && v[t] > v[p]) { ++t; }
    
    swap(v[p], v[t-1]);
    reverse(v, p+1, v.size()-1);
    
    return true;
}




void unipermu1(const vector<int>& a)
{
    vector<int> b = a;
    sort(b.begin(), b.end());
    
    map<int, int> m;
    getstat(b, m);

    vector<int> c(b.size(), 0);
    runipermu(m, c, 0);
}

void unipermu2(const vector<int>& a)
{
    vector<int> b = a;
    sort(b.begin(), b.end());
    do { Util::print(b); } while (nextpermu(b));
}
