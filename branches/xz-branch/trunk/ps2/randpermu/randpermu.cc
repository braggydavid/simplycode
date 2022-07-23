#include <algorithm>
#include <climits>
#include "randpermu.h"

using namespace std;


// Generate a random number r, s.t. i <= r < j;
int randrange(int i, int j)
{
    double x = rand() / ((double) INT_MAX + 1); // 0 <= x < 1
    int r = i + x * (j - i);
    
    return r;
}

// Gnerate a random permutation of 0, ..., n-1;
void randpermu(vector<int> *v, int n)
{
    if (!v) { return; }
    
    int i = 0;
    while (i < n) { v->push_back(i++); }

    for (i = 0; i < n; ++i)
    {
        int r = randrange(i, n);
        swap(v->at(i), v->at(r));
    }
}
