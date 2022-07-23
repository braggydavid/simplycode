#include <algorithm>
#include "wordreverse.h"

using namespace std;

namespace
{ //anonymous

void reverse(string& s, int i, int j)
{
    while(i < j) { swap(s[i++], s[j--]); }
}

bool ischar(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

}

void wordreverse(string& s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if (ischar(s[i]))
        {
            int l = i++;
            while (i < s.size() && ischar(s[i])) { ++i; }
            reverse(s, l, i-1);
        }
    }
}

void stringreverse(string& s)
{
    reverse(s, 0, s.size()-1);
    wordreverse(s);
}

