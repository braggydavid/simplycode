/* [minwindow] Given a word (assume every char is unique in this word) 
   and a string, find the length of the shortest snippet/substring that 
   contains all characters of the word. For example: with word "abc" and 
   the string "a brilliant cat is eating a big cake", the shortest 
   snippet is "big ca", which has length 6. */

#include "miniwindow.h"
#include <map>

int getWindow( map<char, int> &p )
{
    int l, r;
    l = r = p.begin()->second;
    for ( map<char, int>::iterator it = p.begin(), ite = p.end();
                it != ite; ++it )
    {
        if ( it->second < l ) l = it->second;
        if ( it->second > r ) r = it->second;
    }
    return r-l + 1;
                 
}

int miniwindow(const string &whole, const string &word)
{
    map <char, int> p;
    for(int i=0; i<word.size(); ++i)
        p[word[i]] = -1;

    int window=whole.size();
    int total = 0;
    for (int i=0; i<whole.size(); ++i)
    {
        map<char, int>::iterator it = p.find(whole[i]);
        if ( it != p.end() )
        {
            if ( it->second == -1 ) ++ total;
            it->second = i;
            if ( total == word.size() )
            {
                int tw = getWindow(p);
                if ( tw < window ) window = tw;
            }
        }
    }

    return ( window == whole.size() ) ? -1 : window;
}
