#include <queue>
#include <stack>
#include "bfsdfs.h"


using namespace std;
using namespace DS;

void bfs(TNode* t)
{
    if (!t) { return; }

    queue<TNode*> q;
    q.push(t);

    while (!q.empty())
    {
        t = q.front(); q.pop(); PrintTNode(t); 
        
        if (t->lt) { q.push(t->lt); }
        if (t->rt) { q.push(t->rt); }
    }
}

void rdfs(TNode* t)
{
    if (!t) { return; }
    
    PrintTNode(t);
    rdfs(t->lt);
    rdfs(t->rt);
}

void idfs(TNode* t)
{
    if (!t) { return; }

    stack<TNode*> s; 
    while (1)
    {
        for(; t; t=t->lt)
        {
            PrintTNode(t); s.push(t);
        }
        
        if (s.empty()) { break; }   
        
        t = s.top(); s.pop(); t = t->rt;
    }
}

