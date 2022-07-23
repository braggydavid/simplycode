#include <iostream>
#include <queue>
#include "tnode.h"


using namespace std;

namespace DS
{

namespace
{ // anonymous

TNode* rinsert(TNode* t, int val)
{
    if (!t)                  { t = new TNode(val);          }
    else if (t->value > val) { t->lt = rinsert(t->lt, val); }
    else if (t->value < val) { t->rt = rinsert(t->rt, val); }
    
    return t;
}

void rinsert1(TNode** t, int val)
{
    if (!t) { return; }
    TNode* p = *t;
    
    if (!p)                  { *t = new TNode(val);   }
    else if (p->value > val) { rinsert1(&p->lt, val); }
    else if (p->value < val) { rinsert1(&p->rt, val); }
}

void iinsert(TNode** t, int val)
{
    if (!t) { return; }
    
    TNode *p = NULL;
    while (*t)
    {
        p = *t;
        
        if (p->value == val) { return; }
        t = (p->value > val) ? &(p->lt) : &(p->rt);
    }
    
    *t = new TNode(val);
}

void rinorder(TNode* t)
{
    if (!t) { return; }
    
    rinorder(t->lt);
    cout << t->value << " ";
    rinorder(t->rt);
}

void rpreorder(TNode* t)
{
    if (!t) { return; }
    
    cout << t->value << " ";
    rpreorder(t->lt);
    rpreorder(t->rt);
}

void rpostorder(TNode* t)
{
    if (!t) { return; }
    
    rpostorder(t->lt);
    rpostorder(t->rt);
    cout << t->value << " ";
}

void printlayer(TNode* t)
{
    if (!t) { return; }
    
    queue<TNode*> q;
    q.push(NULL);
    
    while (!q.empty())
    {
        if (!t) 
        { 
            cout << "\n"; q.push(NULL);
        }
        else    
        { 
            cout << t->value << " ";
            if (t->lt) { q.push(t->lt); }
            if (t->rt) { q.push(t->rt); }
        }
        t = q.front(); q.pop();
    }
}

void destroy(TNode* t)
{
    if (!t) { return; }

    destroy(t->lt);
    destroy(t->rt);
    delete t;
}

} // anonymous namespace



TNode* MakeTree(const vector<int>& v)
{
    TNode* t = NULL;
    for (int i = 0; i < v.size(); ++i)
    {
        t = rinsert(t, v[i]);
    }
    return t;
}

void DestroyTree(TNode* t)
{
    destroy(t);
}

void PrintInOrder(TNode* t)
{
    rinorder(t);
    cout << endl;
}

void PrintPreOrder(TNode* t)
{
    rpreorder(t);
    cout << endl;
}

void PrintPostOrder(TNode* t)
{
    rpostorder(t);
    cout << endl;
}

void PrintLayer(TNode* t)
{
    printlayer(t);
    cout << endl;
}

void PrintTNode(TNode* t)
{
    if (t) { cout << t->value << " "; }
}

} // namespace DS
