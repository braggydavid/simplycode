#include <iostream>
#include <stdexcept>
#include "construct.h"


using namespace std;
using namespace DS;

namespace 
{ // anonymous

int locate(const vector<int>& v, int s, int len, int val)
{
    for (int i = 0; i < len; ++i)
    {
        if (v[s+i] == val) { return i; }
    }
    
    throw runtime_error("locate() failed.");
}

int getlen(const vector<int>& v, int s, int len, int val)
{
    int i = 0;
    while (i < len && v[s+i] <= val) { ++i; }
    return i;
}

} // anonymous


// Note: vector 'a' carries pre-order traversal sequence.
//       vector 'b' carries in-order traversal sequence.
TNode* construct(const vector<int>& a, int s1,
                 const vector<int>& b, int s2,
                 int len)
{
    if (len <= 0) { return NULL; }
   
    int m = s2 + locate(b, s2, len, a[s1]);
 
    int ls = m-s2;
    int rs = len - (ls+1);
    
    TNode* t = new TNode(a[s1]);
    t->lt = construct(a, s1+1, b, s2, ls);
    t->rt = construct(a, s1+ls+1, b, m+1, rs);
    
    return t;
}

TNode* construct(const vector<int>& a, int s, int len)
{
    if (len <= 0) { return NULL; }

    int ls = getlen(a, s, len, a[s]);

    TNode* t = new TNode(a[s]);
    t->lt = construct(a, s+1, ls-1);
    t->rt = construct(a, s+ls, len-ls);
    
    return t;
}

