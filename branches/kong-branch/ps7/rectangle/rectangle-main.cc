#include "rectangle.h"

int main()
{
    uint t1[] = { 2, 6 };
    uint t2[] = { 5, 6 };
    uint t3[] = { 2, 4, 4, 3, 3, 2, 5, 2, 6, 2, 7, 2 };

    std::vector<uint> v1;
    for (int i=0; i<sizeof(t1) / sizeof(t1[0]); ++i)
        v1.push_back(t1[i]);
    
    std::vector<uint> v2;
    for (int i=0; i<sizeof(t2) / sizeof(t2[0]); ++i)
        v2.push_back(t2[i]);

    std::vector<uint> v3;
    for (int i=0; i<sizeof(t3) / sizeof(t3[0]); ++i)
        v3.push_back(t3[i]);


    rectangle(v1);
    rectangle(v2);
    rectangle(v3);

    return 0;
}
