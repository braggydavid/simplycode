/* [rotatevector] Rotate a one-dimensional vector of n elements left 
   by i positions. For instance, with n=8 and i=3, the vector abcdefgh 
   is rotated to defghabc. Please rotate the vector in time proportional to n. */

#include "rotatevector.h"

using namespace std;


void reverse(string& s, int l, int r)
{
    while ( l < r ) { swap(s[l++], s[r--]); }
}

void rotatevector(string& s, uint k)
{
    int n = s.size() - 1;
    k %= s.size();
    
    reverse(s, 0, n);
    reverse(s, 0, n-k);
    reverse(s, n-k+1, n);

}
