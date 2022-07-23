#include <algorithm>
#include "randgen.h"

namespace 
{
    enum {MaxInt=10000};
}

namespace Util
{

using namespace std;

int RandGen::GetRand()
{
    return rand() % MaxInt;
}
    
void RandGen::GetRandVector(vector<int> *v, int n)
{
    if (!v) { return; }
    
    for (int i = 0; i < n; ++i)
    {
        v->push_back(rand() % MaxInt);
    }
}

void RandGen::GetSortedRandVector(vector<int> *v, int n)
{
    GetRandVector(v, n);
    sort(v->begin(), v->end());
}

} // namespace Util
