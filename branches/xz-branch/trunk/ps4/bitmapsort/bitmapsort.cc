#include <cassert>
#include <string>
#include <iostream>
#include "bitmapsort.h"

using namespace std;

const int kmax = 10000000;
    
class bitmap
{
public:
    bitmap(uint n): num(n)
    {
        bits = new bool[num];
        for (int i = 0; i < num; i++) { bits[i] = false; }
    }

    ~bitmap() { delete [] bits; bits = NULL; }

    void set(uint i) 
    { assert(i < num); bits[i] = true;  }
    void clear(uint i) 
    { assert(i < num); bits[i] = false; }
    bool test(uint i) const 
    { assert(i < num); return bits[i];  }
    
private:
    bool *bits;
    uint num;
};

void bitmapsort(vector<int>& a)
{
    bitmap record(kmax);
    int i = 0, j = kmax;
    while (i < a.size()) { record.set(a[i++]); }
    while (i > 0) 
    { 
        if (record.test(--j)) { a[--i] = j; } 
    }
}
