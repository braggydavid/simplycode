#include <iostream>
#include "print.h"

using namespace std;

namespace Util
{

void print(int x)
{
    cout << x << endl;
}

void print(const vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin();
         it != l.end(); ++ it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

} // namespace Util
