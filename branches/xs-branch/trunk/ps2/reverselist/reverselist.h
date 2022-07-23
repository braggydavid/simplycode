#ifndef INCLUDED_TEST
#define INCLUDED_TEST

#include "lnode.h"

// Iteratively reverse the singly-linked list.
DS::LNode* ireverse(DS::LNode* h);

// Recursively reverse the singly-linked list;
DS::LNode* rreverse(DS::LNode* h, DS::LNode* s);

void rreverse(DS::LNode** h);

#endif /* INCLUDED_TEST */
