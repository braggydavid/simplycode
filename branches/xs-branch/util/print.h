#ifndef INCLUDED_UTIL
#define INCLUDED_UTIL

#include <vector>
#include <list>

namespace Util
{

void print(int x);
void print(const std::vector<int> &v);
void print(const std::list<int> &v);

void printbinary(unsigned int x);

} // namespace Util


#endif /* INCLUDED_UTIL */
