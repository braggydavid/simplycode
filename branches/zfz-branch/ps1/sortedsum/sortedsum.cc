#include <vector>
#include <iostream>

#include "sortedsum.h"


using namespace std;

bool has2sum(vector<int>& v, int sum, uint start)
{
    int l = min(start, v.size()-1), r = v.size()-1;
    
    while(l < r)
    {
        int t = v[l] + v[r];
        
        if (t == sum) { return true; }
        
        t > sum ? --r : ++l;
    }
    
    return false;
}

vector <pair<int, int> >
get2sum(vector<int>& v, int sum)
{
    vector<pair<int, int> > pairs;
    int l = 0, r = v.size()-1;

    while(l < r)
    {
        int t = v[l] + v[r];

        if (t == sum)
        {
            pairs.push_back(pair<int, int> (v[l], v[r]));
            
            do { ++ l; } while (l < r && v[l] == v[l-1]);
            do { -- r; } while (l < r && v[r] == v[r+1]);
        }
        else 
        {
            t > sum? --r : ++ l;
        }
    }
    
    return pairs;
}

/* this version return true, if it three two elements */
bool has3sum(vector<int>& v, int sum, uint start)
{
    //if (start < 0 || start >= v.size())
    //    return false;
    for (int i = min(start, v.size()); i < v.size()-3; ++i)
    {
        int adjusted_sum = sum - v[start];
        
        if (has2sum(v, sum, i+1)) { return true; }
    }
    return false;
}




