/* [rectangle] Find the largest rectangle in a histogram: 
   given a histogram represented in an array, find the rectangle that has the largest area. */

#include <string>
#include<vector>
#include <iostream>
using namespace std;

class Rectangle
{
    public:
        int x1;
        int y1;
        int x2;
        int y2;
};

typedef unsigned int uint;

Rectangle rectangle( const vector<uint>& v );
