/*
   给定一个int数组和一个int变量叫sum，返回是否有数组中的2个数的和等于sum.
 */

#include <vector>
#include <iostream>

using namespace std;

typedef unsigned int uint;

bool has2sum(vector<int>& v, int sum, uint start=0);

vector < pair< int, int> >
get2sum(vector<int>& v, int sum);

/* this version return true, if it three two elements */
bool has3sum(vector<int>& v, int sum, uint start=0);



