/* [rectangle] Find the largest rectangle in a histogram: 
   given a histogram represented in an array, find the rectangle that has the largest area. */
#include "rectangle.h"
#include <stack>

void getMaxRectangle( 
        stack<uint>& cache,
        const vector<uint>& v,
        int x,
        int heightLimit,
        int& size,
        Rectangle& r)
{
    while ( !cache.empty() && v[cache.top()] > heightLimit )
    {
        int t = v[cache.top()] * ( x - cache.top() );
        if ( t > size )
        {
            size = t;
            /* r.x1 = cache.top(); r.y1 = 0; r.x2 = x; r.y2 = v[cache.top()]; */
        }
        cache.pop();
    }
}

Rectangle rectangle( const vector<uint>& v )
{
    Rectangle r;
    int size =0;

    stack<uint> cache;

    for( int i=0; i<v.size(); ++i )
    {
        if ( !cache.empty() && v[i] < v[cache.top()] )
        {
            getMaxRectangle( cache, v, i, v[i], size, r );
        }
        //if ( cache.empty() || v[i] > cache.top() )
        cache.push(i);
    }
    getMaxRectangle( cache, v, v.size(), 0, size, r );

    std::cerr << "size is: " << size << std::endl;

    return r;
}
