#include "bitop.h"
#include <iostream>

int main()
{
    std::cerr << ibitadd(1234, 345) << " " << rbitadd(1234, 345) << std::endl;
    std::cerr << bitminus(12344, 345) << std::endl;
    std::cerr << bitmulti(44, 25) << std::endl;
    std::cerr << rbitdiv(12344, 345) << std::endl;
    return 0;
}
