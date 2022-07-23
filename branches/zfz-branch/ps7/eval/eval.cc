#include "eval.h"
#include <iostream>

using namespace std;

int getvar(queue<int>& e)
{
    int x = e.front(); e.pop();
    if (e.empty()) { return x; }
    
    while (e.front() == '*' || e.front() == '/')
    {
        char op = e.front(); e.pop();
        int var = e.front(); e.pop();
        x = (op == '*') ? x * var : x / var;
        
        if (e.empty()) { break; }
    }
    
    return x;
}

int eval(queue<int>& e)
{
    int x = getvar(e);;
    while (!e.empty())
    {
        char op = e.front(); e.pop();
        int y = getvar(e);
        x = (op == '+') ? x + y : x - y;
    }
    return x;
}

