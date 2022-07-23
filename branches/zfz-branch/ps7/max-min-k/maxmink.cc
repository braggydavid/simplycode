#include <stack>
#include <map>
#include <cassert>

#include "maxmink.h"


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


int popstack(stack<Node>& st, int k, int val, int idx, int* mm)
{
    int width = 0;
    while (!st.empty() && st.top().val > val)
    {
        width = idx - st.top().idx;
        if (width >= k && st.top().val > *mm)
        {
            *mm = st.top().val;
        }
        st.pop();
    }
    
    return (idx - width);
}

} // anonymous


int maxmink1(const vector<int>& v, int k)
{
    stack<Node> st;
    
    int i = 0, j = 0, mm = 0;
    while (i < v.size())
    {
        if (st.empty() || st.top().val <= v[i]) 
        { 
            st.push(Node(v[i], j)); j = ++i; 
        }
        else 
        {
            j = popstack(st, k, v[i], i, &mm);        
        }
    }
    popstack(st, k, mm, v.size(), &mm);
        
    return mm;
}

int maxmink2(const vector<int>& v, int k)
{
    stack<Node> st;
    int mm = 0;
    
    for (int i = 0; i < v.size(); ++i)
    {
        int val = v[i];
        if (st.empty() || st.top().val < val) 
        { 
            st.push(Node(val, i)); continue;
        }
        
        int idx = popstack(st, k, val, i, &mm);
        if (st.empty() || st.top().val < val) 
        { 
            st.push(Node(val, idx)); 
        }
    }
    popstack(st, k, mm, v.size(), &mm);
        
    return mm;
}

int maxmink3(const vector<int>& v, int k)
{
    map<int, int> m;
    map<int, int>::iterator itr;
    
    int mm = 0;
    
    for (int i = 0; i < v.size(); ++i)
    {
        itr = m.find(v[i]);
        itr != m.end() ? itr->second++ : m[v[i]] = 1;
        
        if (i >= k) 
        { 
            itr = m.find(v[i-k]);
            if (itr->second > 1) { itr->second--; }
            else                 { m.erase(itr);  }
        }
        
        if (i >= k-1)
        {
            itr = m.begin();
            if (mm < itr->first) { mm = itr->first; }
        }
    }
    return mm;
}

