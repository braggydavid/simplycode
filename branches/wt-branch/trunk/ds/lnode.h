#ifndef INCLUDED_LNODE
#define INCLUDED_LNODE

#include <vector>

namespace DS
{

class LNode
{
public:
    int value;
    LNode* prev;
    LNode* next;

    LNode()
    : value(0), prev(NULL), next(NULL)
    {}
    LNode(int v) 
    : value(v), prev(NULL), next(NULL) 
    {}
    ~LNode() { prev = next = NULL; }
};

LNode* MakeList(const std::vector<int>& v);
void FreeList(LNode* pnode);

void PrintLNode(const LNode& node);
void PrintList(const LNode* pnode);

} // namespace ds


#endif /* INCLUDED_LNODE */
