#include "randpermu.h"
#include "print.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v;

    const int k = 10;

    for (int i = 1; i < k; ++i)
    {
        randpermu(&v, i);
        Util::print(v);
        v.clear();
    }
    
    return 0;
}
