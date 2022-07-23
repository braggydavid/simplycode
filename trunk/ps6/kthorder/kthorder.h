#ifndef INCLUDE_KTHORDER
#define INCLUDE_KTHORDER

#include <vector>
#include <iostream>

int partition(std::vector<int> &a, int l, int h, int pidx);
int kthnum(std::vector<int> &a, int l, int h, int k);
int kthorder(std::vector<int>& a, int k);

#endif /* INCLUDE_KTHORDER */
