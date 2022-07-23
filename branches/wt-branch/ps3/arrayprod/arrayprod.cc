/* [arrayprod]Given an integer array A, compute array B s.t. (1) B(i) equals to the product of all elements, except A(i), of A; (2) Using the division operator "/" is NOT allowed; (3) assume no overflow problem. */
#include "arrayprod.h"

vector<int> arrayprod(const vector<int>& v)
{
    int n= v.size();
    vector<int> f(n+1, 1), b(n+1, 1), r(n, 0);

    for (int i = 0; i < n; ++i) 
    {
        f[i+1] = f[i] * v[i];
        b[n-i-1] = b[n-i] * v[n-i-1];
    }

    for (int i = 0; i < n; ++i)
    {
        r[i] = f[i] * b[i+1];
    }
    return r;
}

