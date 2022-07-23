#include <cstdlib>
#include <algorithm>
#include <queue>
#include "kthorder.h"

using namespace std;

// ------------------------------------
// partition based randomized solution
// ------------------------------------

//
// O(n) time to partition an array wrt pivot
// -- a sub-procedure in quicksort
//
int partition(vector<int> &a, int l, int h, int z)
{
    int j = l, pivot = a[z];
    swap(a[h], a[z]);
    for (int i = l; i < h; i++)
    {
        if (a[i] <= pivot) { swap(a[i], a[j++]); }
    }
    swap(a[j], a[h]);
    return j;  // Note that j is the original index in a
}

//
// O(n) in average finding k-th smallest integer 
//
int kthnum(vector<int> &a, int l, int h, int k)
{
    if ((h < l) or (k > h + 1)) return -1; 
    if (h == l) return a[l];

    int i = rand() % (h - l + 1) + l; 
    int m = partition(a, l, h, i) + 1;

    if (m == k) return a[m-1];
    else if (m > k) return kthnum(a, l, m-2, k);
    else return kthnum(a, m, h, k); // since m is the original index, we do not decrease k
}

// ------------------------------------
// priority-queue based solution
// ------------------------------------

struct cmp
{
    // comparator for max-heap
    bool operator()(int x, int y) { return x < y; }
};

typedef priority_queue<int, vector<int>, cmp> pqueue;

int kthorder(vector<int>& a, int k)
{
    int i = 0;
    pqueue q;

    while (i < k) { q.push(a[i++]); }

    while (i < a.size())
    {
        if (a[i] < q.top())
        {
            q.pop();
            q.push(a[i]);
        }
        ++i;
    }
    return q.top();
}
