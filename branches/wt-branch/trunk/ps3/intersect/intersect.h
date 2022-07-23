#ifndef INCLUDED_INTERSECT
#define INCLUDED_INTERSECT

#include <vector>

std::vector<int> intersect(const std::vector<int>& a, const std::vector<int>& b);
std::vector<int> unify(const std::vector<int>& a, const std::vector<int>& b);
std::vector<int> substract(const std::vector<int>& a, const std::vector<int>& b);

std::vector<int> intersect1(const std::vector<int>& a, const std::vector<int>& b);
std::vector<int> intersect2(const std::vector<int>& a, const std::vector<int>& b);

std::vector<int> minus1(const std::vector<int>& a, const std::vector<int>& b);
std::vector<int> minus2(const std::vector<int>& a, const std::vector<int>& b);

#endif /* INCLUDED_INTERSECT */
