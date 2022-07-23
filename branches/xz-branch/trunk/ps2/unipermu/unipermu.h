#ifndef INCLUDED_UNIPERMU
#define INCLUDED_UNIPERMU

#include <vector>
#include <map>

// generate next permutation for a given permutation.
bool nextpermu(std::vector<int>& v);

// major algorithm for permuation.
void runipermu(const std::map<int, int>& m, std::vector<int>& r, int k);

// use runipermu()
void unipermu1(const std::vector<int>& a);
// use nextpermu()
void unipermu2(const std::vector<int>& a);


#endif /* INCLUDED_UNIPERMU */
