#ifndef INCLUDED_LCP
#define INCLUDED_LCP

#include "tnode.h"


int lcp(DS::TNode* t, int x, int y, DS::TNode** p);
void rbst_lcp(DS::TNode* t, int x, int y, DS::TNode** p);
void ibst_lcp(DS::TNode* t, int x, int y, DS::TNode** p);


#endif /* INCLUDED_LCP */
