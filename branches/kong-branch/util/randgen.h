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

class RG
{
    static RandGen __rg;

    // Generate a random integer.
    static int getRand() { return __rg.GetRand(); }
    // Generate a random vector of size n.
    static void getRandVector(std::vector<int> *v, int n) { __rg.GetRandVector(v, n); }
    // Generate a sorted random vector of size n.
    static void getSortedRandVector(std::vector<int> *v, int n) { __rg.GetSortedRandVector(v, n); }
};

} // namespace Util

#endif /* INCLUDED_RANDGEN */
