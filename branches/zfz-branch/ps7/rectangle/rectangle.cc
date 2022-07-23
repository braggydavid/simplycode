#include "rectangle.h"

#include <vector>
#include <stack>


using namespace std;

namespace
{ // anonymous

typedef struct Node
{
   int val;
   int idx;
   Node(int val, int idx) : val(val), idx(idx)
   {}
} Node;


int popstack(stack<Node>& st, int val, int idx, int* r)
{
    int i = -1;
    while (!st.empty() && st.top().val > val)
    {
        i = st.top().idx;
            
        int t = st.top().val * (idx - i);
        if (*r < t) { *r = t; }
        
        st.pop();
    }
    return idx;
}

} // anonymous


int rectangle(const vector<int>& hist)
{
    stack<Node> st;
    int r = 0;
    
    for (int i = 0; i < hist.size(); ++i)
    {
        int val = hist[i];
        if (st.empty() || st.top().val < val)
        {
            st.push(Node(val, i));
            continue;
        }
        
        int j = popstack(st, val, i, &r);
        
        if (st.empty() || st.top().val < val)
        {
            st.push(Node(val, j));
        }
    }
    popstack(st, 0, hist.size(), &r);
    
    return r;
}

