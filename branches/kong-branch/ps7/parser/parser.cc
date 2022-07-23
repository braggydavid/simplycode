/* Evaluate a simple math expression that includes operators +,-,*,/. Example: 4 + 2*16/8 - 3. */
#include "parser.h"

#include <stack>

int cal(stack<int>& vs, stack<char>& ops)
{
    int t = vs.top(); vs.pop();
    if (vs.empty()) { return t; }

    char op = ops.top(); ops.pop();
    return cal( vs, ops ) + ( op == '+' ? t : (-t) );
}

int parser(const string& line)
{

    stack<int> vcache;
    stack<char> opcache;

    stringstream ss(line);
    int t; char op;
    ss >> t;
    vcache.push(t);
    while ( ss >> op >> t)
    {
        int tv = t;
        switch ( op )
        {
            case '*': tv = vcache.top() * t; vcache.pop(); break;
            case '/': tv = vcache.top() / t; vcache.pop(); break;
            case '+':
            case '-': opcache.push(op); break;
        }
        vcache.push(tv);
    }

    t = cal( vcache, opcache );
    cerr << line << " = " << t << endl;
}

