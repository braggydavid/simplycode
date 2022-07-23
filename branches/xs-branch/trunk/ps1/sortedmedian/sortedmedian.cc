#include <algorithm>
#include <cassert>
#include "sortedmedian.h"


using namespace std;

int calc(const vector<int> &a, int l, const vector<int> &b, int s, int len)
{
    // Ensure that a[l] >= b[s];
    if (a[l] < b[s]) { return calc(b, s, a, l, len); }

    int x = (s < b.size()-1) ? min(a[l], b[s+1]) : a[l];
    if (len % 2 == 1) { return x; }

    int y = (l > 0) ? max(a[l-1], b[s]) : b[s];
    return (x + y) / 2;
}

//
// An O(log(n)) algorithm to find median of two sorted arrays.
//
// Note: the algorithm wont return correct result if any input 
// vector is empty. 
// 
int median(const vector<int> &a, const vector<int> &b)
{
    if (a.size() > b.size()) { return median(b, a); }

    int len = a.size() + b.size();
    int t = 0, m = 0, u = 0, v = a.size()-1;
    
    while (u < v)
    {
	m = (u + v) / 2;
	t = len/2 - (m+1);

	a[m] < b[t] ? u = m+1 : v = m;
    }

    t = len/2 - (u+1);

    return calc(a, u, b, t, len);
}

//
// An O(n*log(n)) trivial algorithm to find median of two sorted arrays.
//
int getmedian(const vector<int> &a, const vector<int> &b)
{
    if (a.size() <= 0 || b.size() <= 0)
    {
        return 0x7FFFFFFF;
    }
    
    vector<int> c = a;
    for (int i = 0; i < b.size(); ++i)
    {
        c.push_back(b[i]);
    }
    
    sort(c.begin(), c.end());

    int m = c.size() / 2;
    if (c.size() % 2 == 0)
    {
        return (c[m] + c[m-1])/2;
    }

    return c[m];
}




