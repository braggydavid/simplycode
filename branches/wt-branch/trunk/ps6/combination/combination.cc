#include <vector>
#include "print.h"


using namespace std;


void icomb(int n, int k)
{
    vector<int> v(k, -1);

    for (int r = 0; r >= 0; --r)
    {
        for (int i = v[r]+1; i < n; ++i)
        {
            v[r++] = i;
            if (r >= k) { Util::print(v); --r; }
        }
    }
}

void rcomb(vector<int>& v, int n, int k)
{
    if (k <= 0) { Util::print(v); return; }

    for (int i = n-1; i >= k-1; --i)
    {
        v[k-1] = i;
        rcomb(v, i, k-1);
    }
}
