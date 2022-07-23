#ifndef INCLUDED_TNODE
#define INCLUDED_TNODE


#include <vector>

namespace DS
{

class TNode
{
public:
    int value;
    TNode* pr; // parent
    TNode* lt; // left
    TNode* rt; // right

    TNode()
    : value(0), pr(NULL), lt(NULL), rt(NULL)
    {}
    TNode(int v) 
    : value(v), pr(NULL), lt(NULL), rt(NULL)
    {}
    ~TNode() { pr = lt = rt = NULL; }
};


TNode* MakeTree(const std::vector<int>& v);
void   DestroyTree(TNode* t);
void   PrintInOrder(TNode* t);
void   PrintPreOrder(TNode* t);
void   PrintPostOrder(TNode* t);
void   PrintLayer(TNode* t);
void   PrintTNode(TNode* t);

} // namespace DS


#endif /* INCLUDED_TNODE */
