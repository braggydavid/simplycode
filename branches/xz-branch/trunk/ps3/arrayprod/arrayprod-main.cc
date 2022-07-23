#include "print.h"
#include "arrayprod.h"
#include <vector>

using namespace std;

int main()
{
    
    vector<int> v;
    for (int i=1; i<6; ++i)
    {
        v.push_back(i);
    }

    Util::print(v);
    v = arrayprod(v);
    Util::print(v);

    return 0;
}
