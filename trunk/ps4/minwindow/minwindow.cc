#include <queue>
#include <vector>
#include <map>
#include <string>
#include <iostream>

#include "minwindow.h"


using namespace std;

namespace 
{

int getmin(const map<char, int>& m)
{
    map<char, int>::const_iterator it = m.begin();
    int idx = it->second;
    for (; it != m.end(); ++it)
    {
        if (idx > it->second) { idx = it->second; }
    }
    return idx;
}

int init(const string& s, const string& w, map<char, int>& m)
{
    for (int i = 0; i < w.size(); ++i)
    {
        m.insert(make_pair(w[i], -1));
    }

    map<char, int>::iterator it;
    int j = 0, k = 0;
    for (; k < s.size() && j < m.size(); ++k)
    {
        it = m.find(s[k]);
        if (it != m.end()) 
        { 
            if (it->second == -1) { ++j; }
            it->second = k; 
        }
    }
    return k;
}

struct cmp
{
    bool operator()(int x, int y) { return x > y; }
};

typedef priority_queue<int, vector<int>, cmp> pqueue;

int init(const string& s, const string& w, pqueue& q)
{
    int k = 0;
    for (int i = 0; i < w.size(); ++i)
    {
        string::size_type loc = s.find(w[i]);
        
        if (loc != string::npos) 
        { 
            if (loc > k) { k = loc; }
            q.push((int)loc); 
        }
    }
    return k;
}

} // anonymous


int minwindow1(const string& s, const string& w)
{
    map<char, int> m;
    int i = init(s, w, m);
    if (i >= s.size()) { return -1; }

    map<char, int>::iterator it;
    int d = i - getmin(m);
    
    for (; i < s.size(); ++i)
    {
        it = m.find(s[i]);
        if (it == m.end()) { continue; }

        it->second = i;
        int t = i - getmin(m) + 1;
        if (d > t) { d = t; }
    }
    return d;
}


int minwindow2(const string& s, const string& w)
{
    pqueue q;
    int k = init(s, w, q);
    if (q.size() < w.size()) { return -1; }
    
    int i = q.top(), d = k-i+1;
    char c = s[i];
    while (++i < s.size())
    {
        if (s[i] != c) { continue; }
        q.pop(); q.push(i);
        
        if (i > k) { k = i; }        
        int t = k - q.top() + 1;
        if (d > t) { d = t; }
        
        i = q.top(); c = s[i];
    }
    return d;
}
