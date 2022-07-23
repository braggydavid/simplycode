#include <stdexcept>


using namespace std;

int strcmp1(const char* s1, const char* s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        throw runtime_error("invalid input");
    }

    if (*s1 == *s2)
    {
        return (*s1 == 0) ? 0 : strcmp1(++s1, ++s2);
    }
    
    return (*s1 > *s2) ? 1 : -1;
}

int strcmp2(const char* s1, const char* s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        throw runtime_error("invalid input");
    }

    while (*s1 != 0 && *s2 != 0)
    {
        if (*s1 != *s2) 
        {
            return (*s1 > *s2) ? 1 : -1;
        }
        ++s1; ++s2;
    }
    
    if (*s1 == *s2) { return 0; }
    
    return (*s1 > *s2) ? 1 : -1;
}
