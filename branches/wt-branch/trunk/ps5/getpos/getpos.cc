#include "getpos.h"

using namespace DS;


namespace 
{ // anonymous

void inorder(TNode* t, int x, int* p)
{
    if (!t) { return; }
    
    inorder(t->lt, x, p);
    
    if (t->value <= x) { *p += 1;}
    
    if (t->value <  x) 
    { 
        inorder(t->rt, x, p); 
    }
}

} // anonymous


int getpos(TNode* t, int x)
{
    if (!t) { return -1; }
    
    int r = 0;
    inorder(t, x, &r);
    return r;
}
