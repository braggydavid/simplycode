#ifndef INCLUDED_ROTATEVECTOR
#define INCLUDED_ROTATEVECTOR

/* [rotatevector] Rotate a one-dimensional vector of n elements left 
   by i positions. For instance, with n=8 and i=3, the vector abcdefgh 
   is rotated to defghabc. Please rotate the vector in time proportional to n. */

#include <string>

typedef unsigned int uint;

void rotatevector(std::string& s, uint k);


#endif /* INCLUDED_ROTATEVECTOR */
