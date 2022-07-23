/* [rotatevector] Rotate a one-dimensional vector of n elements left 
   by i positions. For instance, with n=8 and i=3, the vector abcdefgh 
   is rotated to defghabc. Please rotate the vector in time proportional to n. */

#include <vector>
#include <iostream>

using namespace std;

void rotate(vector<char> *elements, int i);
void print(vector<char> *eles);