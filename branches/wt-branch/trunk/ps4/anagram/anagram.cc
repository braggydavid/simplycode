#include <map>
#include <algorithm>

#include "anagram.h"

using namespace std;


vector<vector<string> > anagram(const vector<string>& s)
{
    vector<vector<string> > r;
    map<string, vector<string> > hashtable;

   for(int i = 0; i < s.size(); ++i)
   {
       string w = s[i];
       sort(w.begin(), w.end());
       hashtable[w].push_back(s[i]);
   }

   map<string, vector<string> >::iterator it;
   for(it = hashtable.begin(); it != hashtable.end(); ++it)
   {
       r.push_back(it->second);
   }
   return r;
}

