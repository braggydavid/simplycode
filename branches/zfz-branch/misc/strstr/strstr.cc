#include <cstdlib>
#include <stdexcept>

using namespace std;

namespace
{ //anonymous

bool match(const char* s1, const char* s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        throw runtime_error("null pointer in match()");
    }
    
    if (*s2 == 0) { return true;  }
    if (*s1 == 0) { return false; }
    
    return (*s1 == *s2) ? match(++s1, ++s2) : false;
}

} // anonymous


const char* strstr1(const char* s1, const char* s2)
{
    if (s1 == NULL) { return NULL; }
    if (s2 == NULL) { return s1; }

    while (*s1 != 0)
    {
        if (match(s1, s2))
        {
            return s1;
        }
        ++s1;
    }
    return NULL;
}
