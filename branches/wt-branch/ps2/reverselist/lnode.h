#ifndef INCLUDED_REVERSELIST
#define INCLUDED_REVERSELIST

#include <vector>

namespace ST
{

class LNode
{
public:
    int value;
    LNode* prev;
    LNode* next;

    LNode(int v) 
    : value(v), prev(NULL), next(NULL) 
    {}
    ~LNode() { prev = next = NULL; }
};

LNode* MakeList(const std::vector<int>& v);
void FreeList(LNode* pnode);

void PrintLNode(const LNode& node);
void PrintList(const LNode* pnode);

} // namespace st



#endif /* INCLUDED_REVERSELIST */
