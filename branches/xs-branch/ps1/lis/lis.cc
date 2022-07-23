#include <cassert>
#include "lis.h"


using namespace std;

//
// Function lis0() finds the length of the LIS (longest increasing
// subsequence), not the LIS itself. Finding the length of the LIS 
// requires less complexity than finding the actual LIS.
//
// Hint: Scan the given array/vector, and keep the last element of 
//       all the LIS(es) of various sizes found so far. Here the last 
//       element of a LIS of a given size should be the smallest 
//       of all possible ones.
// 
int lis0(const vector<int> &v)
{
    assert(v.size() > 0);
    if (v.size() == 1) { return v[0]; }

    vector<int> t(1, v[0]); // store element at index 0;
    for (int i = 1; i < v.size(); ++i)
    {
        int c = v[i];
        if (c > t.back()) 
        { 
            t.push_back(c); // store element v[i];
        }
        else
        {
            int b = 0, e = t.size()-1, m;
            // binary search
            while (b < e)
            {
                m = (b + e) / 2;
                c > t[m] ? b = m + 1 : e = m;
            }

            // Note: after the binary search, t[b] >= c;
            
            t[b] = c;   // store element v[i];
        }
    }
    return t.size();
}

// 
// Function lis1() is the same as lis0() except that lis1() stores
// index instead. 
// 
int lis1(const vector<int> &v)
{
    assert(v.size() > 0);
    if (v.size() == 1) { return v[0]; }

    vector<int> t(1, 0); // store index 0 itself.
    for (int i = 1; i < v.size(); ++i)
    {
        int c = v[i];
        if (c > v[t.back()]) 
        { 
            t.push_back(i); // store index i; 
        }
        else
        {
            int b = 0, e = t.size()-1, m;
            while (b < e)
            {
                m = (b + e) / 2;
                c > v[t[m]] ? b = m + 1 : e = m;
            }
            
            t[b] = i;   // store index i;
        }
    }
    return t.size();
}

//
// Function lis2() finds the LIS itself. lis2() differs from lis1() 
// in that lis2() employs another vector to keep track of the 
// "previous element".
//
void lis2(const vector<int> &v, list<int> *r)
{
    if (v.size() == 0 || r == NULL) { return; }

    vector<int> t(1,  0);

    // p[i] = j, s.t  j < i && v[j] < v[i];
    // and p[i] = -1 if no such j exits.
    vector<int> p(1, -1); 

    for (int i = 1; i < v.size(); ++i)
    {
        int c = v[i];
        if (c > v[t.back()]) 
        { 
            p.push_back(t.back());
            t.push_back(i); 
        }
        else
        {
            int b = 0, e = t.size()-1, m;
            while (b < e)
            {
                m = (b + e) / 2;
                c > v[t[m]] ? b = m + 1 : e = m;
            }
            
            t[b] = i;
            // p.push_back(t[b-1]); will fault if b equals 0;
            b > 0 ? p.push_back(t[b-1]) : p.push_back(-1);
        }
    }
    
    // use the p vector to recover the actual LIS.
    for (int i = t.back(); i >= 0; i = p[i])
    {    
        r->push_front(v[i]);
    }
}

