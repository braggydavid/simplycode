#include <iostream>
#include "lnode.h"

namespace DS
{

using namespace std;

LNode* MakeList(const vector<int>& v)
{
    LNode* p = NULL;
    LNode* c = NULL;

    if (v.size() > 0)
    {
        p = new LNode(v[0]);
        c = p;
    }

    for (int i = 1; i < v.size(); ++i)
    {
        c->next = new LNode(v[i]);
        c = c->next;
    }

    return p;
}

void FreeList(LNode* p)
{
    LNode* n = NULL;
    while (p)
    {
        n = p->next; delete p; p = n;
    }
}

void PrintLNode(const LNode& node)
{
    cout << node.value << endl;
}

void PrintList(const LNode* pnode)
{
    int flag = 0;
    while (pnode)
    {
        cout << pnode->value << " ";
        pnode = pnode->next;
        flag = 1;
    }
    
    if (flag) { cout << endl; }
}

} // namespace DS
