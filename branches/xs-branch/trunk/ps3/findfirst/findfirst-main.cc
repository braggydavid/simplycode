#include "findfirst.h"
#include "randgen.h"
#include <iostream>
#include <climits>

int main()
{
    int a[] = { 0, 1, 2, 5, 5, 5, 8, 9, 10 };
    std::vector<int> v;
    for ( int i=0; i<sizeof(a) / sizeof(a[0]); ++i )
    {
        v.push_back(a[i]);
    }
    std::cerr << findfirst(v, 5) << std::endl;
    std::cerr << findfirst(v, -2) << std::endl;
    std::cerr << findfirst(v, 12) << std::endl;
    std::cerr << findfirst(v, 7) << std::endl;
    std::cerr << findfirst(v, 9) << std::endl;
    std::cerr << findfirst(v, 10) << std::endl;
    std::cerr << findfirst(v, 0) << std::endl;
    
    return 0;
}
