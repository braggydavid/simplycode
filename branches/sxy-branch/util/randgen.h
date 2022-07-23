#ifndef INCLUDED_RANDGEN
#define INCLUDED_RANDGEN

#include <vector>
#include <cstdlib>

namespace Util
{

class RandGen
{
public:
    RandGen() 
    {
        std::srand(0);
    }
    
    // Generate a random integer.
    int GetRand();    
    // Generate a random vector of size n.
    void GetRandVector(std::vector<int> *v, int n);
    // Generate a sorted random vector of size n.
    void GetSortedRandVector(std::vector<int> *v, int n);
};

} // namespace Util

#endif /* INCLUDED_RANDGEN */
