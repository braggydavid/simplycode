#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

#include "print.h"
#include "mergesort.h"

using namespace std;

namespace { // anonymous

DS::LNode* merge(DS::LNode* p1, DS::LNode* p2)
{
    DS::LNode head;
    DS::LNode* pr = &head;

    while (p1 && p2)
    {
        if (p1->value < p2->value)
        {
            pr->next = p1;
            pr = p1;
            p1 = p1->next;
        }
        else
        {
            pr->next = p2;
            pr = p2;
            p2 = p2->next;
        }
    }
    pr->next = p1 ? p1 : p2;
    
    return head.next;
}

void merge(vector<int>&v, int s, int len1, int len2)
{
   vector<int> t;
   int s1 = s, s2 = s1+len1, e1 = s+len1-1, e2 = s2+len2-1;

   while(s1 <= e1 && s2 <= e2)
   {
       int x = v[s1] < v[s2] ? v[s1++] : v[s2++];
       t.push_back(x);
   }

   while (s1 <= e1) { t.push_back(v[s1++]); }
   while (s2 <= e2) { t.push_back(v[s2++]); }

   for (int i = 0; i < t.size(); ++i)
   {
       v[s+i] = t[i];
   }
}

} // anonymous namespace


DS::LNode* rmergesortlist(DS::LNode** p, int n)
{
    if (n <= 1) 
    { 
        DS::LNode* t = *p; *p = t->next; t->next = NULL; 
        return t;
    }
    
    DS::LNode* l = rmergesortlist(p, n/2);
    DS::LNode* r = rmergesortlist(p, n-n/2);
   
    return merge(l, r);
}


void rmergesort(vector<int>& v, int s, int e)
{
    if (s >= e) { return; }

    int m = (s + e) / 2;
    rmergesort(v, s, m);
    rmergesort(v, m+1, e);

    merge(v, s, m-s+1, e-m);
}


void imergesort(vector<int>& v, int s, int e)
{
    int len = e - s + 1;
    for (int k = 1; k < len; k <<= 1)
    {
        for (int i = 0; i+k < len; i += k*2)
        {
            merge(v, i, k, min(len-(i+k), k));
        }
    }
}
