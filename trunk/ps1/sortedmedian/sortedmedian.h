#ifndef INCLUDED_SORTEDMEDIAN
#define INCLUDED_SORTEDMEDIAN

#include <vector>

int calc(const std::vector<int> &a, int l, 
         const std::vector<int> &b, int s, 
         int len);
int median(const std::vector<int> &a, const std::vector<int> &b);
int getmedian(const std::vector<int> &a, const std::vector<int> &b);


#endif /* INCLUDED_SORTEDMEDIAN */
