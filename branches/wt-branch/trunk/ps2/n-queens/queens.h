#ifndef QUEENS_H
#define QUEENS_H

#include <vector>

// iteratively solve the n-queen problem
void isolve(std::vector<int> &p, int &cnt);
// recursively solve the n-queen problem
void rsolve(std::vector<int> &p, int k, int &cnt);

#endif /* QUEENS_H */
