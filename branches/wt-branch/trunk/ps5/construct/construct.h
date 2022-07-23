#ifndef INCLUDED_CONSTRUCT
#define INCLUDED_CONSTRUCT

#include <vector>
#include "tnode.h"

DS::TNode* construct(const std::vector<int>& a, int s1,
                     const std::vector<int>& b, int s2,
                     int len);

DS::TNode* construct(const std::vector<int>& a, int s, int len);

#endif /* INCLUDED_CONSTRUCT */
