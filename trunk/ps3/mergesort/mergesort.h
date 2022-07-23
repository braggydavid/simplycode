#ifndef INCLUDED_MERGESORT
#define INCLUDED_MERGESORT

#include <vector>
#include "lnode.h"

DS::LNode* rmergesortlist(DS::LNode** p, int n);

void rmergesort(std::vector<int>& v, int s, int e);
void imergesort(std::vector<int>& v, int s, int e);


#endif /* INCLUDED_MERGESORT */
