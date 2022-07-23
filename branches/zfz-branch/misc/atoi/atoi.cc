#include <stdexcept>

using namespace std;

int atoi1(const char* s)
{
    if (s == NULL) 
    {
        throw runtime_error("null pointer");
    }

    bool sign = false;
    int r = 0;
    
    // skip white space
    while (*s == ' ') { ++s; }
    
    if (*s == '-') { sign = true; ++s; }
    if (*s == '+') { ++s; }
    
    while (*s >= '0' && *s <= '9')
    {
        r = r*10 + (*s - '0'); // might overflow
        ++s;
    }

    if (*s != 0) { r = 0; }

    return sign ? -r : r;
}

int atoi2(const char* s)
{
    if (s == NULL) 
    {
        throw runtime_error("null pointer");
    }

    bool sign = false;
    int r = 0;
    
    // skip white space
    while (*s == ' ') { ++s; }
    
    if (*s == '-') { sign = true; ++s; }
    if (*s == '+') { ++s; }
    
    if (*s == 0)
    {
        throw runtime_error("invalid input");
    }
    
    while (*s >= '0' && *s <= '9')
    {
        r = r*10 + (*s - '0'); // might overflow
        ++s;
    }

    if (*s != 0)
    {
        throw runtime_error("invalid input");
    }

    return sign ? -r : r;
}
