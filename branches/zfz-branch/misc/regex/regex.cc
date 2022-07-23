#include <stdexcept>

#include "regex.h"


using namespace std;

namespace
{ //anonymous

bool validstart(char c)
{
   return (c >= 'a' && c <= 'z') || c == '.';
}

bool validchar(char c)
{
   return (c >= 'a' && c <= 'z') || c == '.' || c == '*';
}

bool match(const string& str, int k, const string& pat, int r)
{
   if (r >= pat.size()) { return true;  }
   if (k >= str.size()) { return false; }

   if (!validchar(pat[r]))
   {
       throw runtime_error("invalid parttern: " + pat);
   }

   if (r+1 < pat.length() && pat[r+1] == '*') // look ahead
   {
       char prev = pat[r];
       do { ++r; } while (pat[r] == '*');

       while (k < str.length())
       {
           if (match(str, k, pat, r))
           {
               return true;
           }
           if (prev != '.' && prev != str[k])
           {
               return false;
           }
           ++k;
       }
       return false;
   }
   else
   {
       if (pat[r] != '.' && pat[r] != str[k])
       {
           return false;
       }
       return match(str, ++k, pat, ++r);
   }
}

} // anonymous


bool ismatch(const string& str, const string& pat)
{
   if (!validstart(pat[0]))
   {
       throw runtime_error("invalid parttern: " + pat);
   }

   for (int i = 0; i < str.length(); ++i)
   {
       if (match(str, i, pat, 0))
       {
           return true;
       }
   }

   return false;
}


