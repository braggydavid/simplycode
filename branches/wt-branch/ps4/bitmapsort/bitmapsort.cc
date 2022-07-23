#include <cassert>
#include <string>
#include <iostream>
#include "bitmapsort.h"

using namespace std;

const int maxnum = 10000000;
    
class bitmap
{
public:
    bitmap(int n): num(n)
    {
        bits = new bool[num];
        for (int i = 0; i < num; i++) { bits[i] = false; }
    }

    ~bitmap() { delete [] bits; bits = NULL; }

    void set(int i) { assert(i <= num && i >= 1); bits[i-1] = true; }
    void clear(int i) { assert(i <= num && i >= 1); bits[i-1] = false; }
    bool test(int i) const { assert(i <= num && i >= 1); return bits[i-1]; }
    
private:
    bool *bits;
    int num;
};

void bitmapsort(vector<int>& a)
{
    bitmap record(maxnum);
    int i = 0, j = maxnum;
    while (i < a.size()) { record.set(a[i++]); }
    while (i > 0) 
    { 
        if (record.test(j--)) { a[--i] = j+1; } 
    }
    return;
}
