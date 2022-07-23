#include "reverselist.h"

using namespace ST;

// Iteratively reverse the singly-linked list.
LNode* ireverse(LNode* h)
{
    LNode* p = NULL;
    LNode* n = NULL;
    
    while (h)
    {
        n = h->next; 
        h->next = p;
        p = h; h = n; 
    }
    
    return p;
}

// Recursively reverse the singly-linked list;
LNode* rreverse(LNode* h, LNode* s)
{
    if (!h) { return s; }
    
    LNode* n = h->next;
    h->next = s;
    
    return rreverse(n, h);
}

