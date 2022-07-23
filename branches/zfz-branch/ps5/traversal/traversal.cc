#include <stack>
#include "traversal.h"

using namespace std;
using namespace DS;


void rinorder(TNode* t)
{
    if (!t) { return; }
    
    rinorder(t->lt);
    PrintTNode(t);
    rinorder(t->rt);
}

void iinorder(TNode* t)
{
    if (!t) { return; }

    stack<TNode*> s;
    while (1)
    {
        while(t) { s.push(t); t = t->lt; }
        
        if (s.empty()) { break; }
        
        t = s.top(); s.pop(); PrintTNode(t);
        t = t->rt;
    }
}

void rpostorder(TNode* t)
{
    if (!t) { return; }
    
    rpostorder(t->lt);
    rpostorder(t->rt);    
    PrintTNode(t);
}

void ipostorder(TNode* t)
{
    if (!t) { return; }
    
    std::stack<TNode*> s;
    TNode *p = NULL;
    
    while (1)
    {
        while(t) { s.push(t); t = t->lt; }

        if (s.empty()) { break; }

        t = s.top();         
        if (t->rt && p != t->rt)
        {    
            t = t->rt;
        }
        else
        {
            PrintTNode(t); s.pop();
            p = t; t = NULL; 
        }
    }
}

