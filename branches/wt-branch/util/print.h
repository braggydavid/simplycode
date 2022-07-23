#ifndef INCLUDED_UTIL
#define INCLUDED_UTIL

#include <vector>
#include <string>
#include <list>

namespace Util
{
    void print(int x);
    void print(const std::vector<int> &v);
    void print(const std::vector<std::string> &v);
    void print(const std::list<int> &v);
} // namespace Util


#endif /* INCLUDED_UTIL */
