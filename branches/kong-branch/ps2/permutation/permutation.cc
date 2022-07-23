

/*

Print all the permutation of a given array (implement both iterative and recursive algorithms)

 */

#include <iostream>
#include <cassert>

#include "util.h"
#include "permutation.h"

using namespace std;


bool isValid(const vector<int>& v, int end, int value)
{
    for (int i=0; i< end; ++i)
    {
        if (v[i] == value) { return false; }
    }
    return true;
}

void print(const string& values, const vector<int>& indexes)
{
    assert (values.size() >= indexes.size());
    for (int i=0; i<indexes.size(); ++i)
    {
        cerr << values[ indexes[i] ];
    }
    cerr << std::endl;
}
//sort of brute force solution
void ipermu(const std::string& array) 
{
    int n = array.size(), p=0;
    vector<int> pv(n, -1);
    while (p >= 0)
    {
        ++ pv[p];
        while ( pv[p] < n && !isValid(pv, p, pv[p]) ) { ++ pv[p]; }

        if (pv[p] < n && p == n-1) 
        { 
            print(array, pv);
        }
        else 
        {
            pv[p] >= n ? --p : pv[++p] = -1; 
        }
    }
}

void reverse(vector<int>& v, int b, int e)
{
    // for this one, I prepare to keep what it was, 
    // remember normally, when we work on a array, 
    // we inlude the leftest element, exclude the rightest element
    for (int i=b, j=e-1; i<j; ++i, --j)
    {
        swap(v[i], v[j]);
    }
}

/*
find next permutation of current one, 
return false if it is the last permutation
true otherwise.
    the solution, I provided here, assumes that there is no duplicated value
    if there is some, if will skip the duplicated permuation
    so the next permutation of 121 will be 211 instead of 121
   */
bool nextPermu(vector<int>& v)
{
    int p = v.size() -2;
    for (; p >= 0 && v[p] >= v[p+1]; -- p) ;

    // nextPermu means it will return next permutation, the one behind the 
    // last permutation should be the first one, right?
    if (p == -1)
    {
        // you reach the last permutation, so reverse the vector, and return false
        reverse(v, 0, v.size());
        return false;
    }

    int t = p+1;
    for (; t < v.size() && v[t] > v[p]; ++t) ;
    swap(v[p], v[t-1]);
    reverse(v, p+1, v.size());

    return true;
}

void ipermu_next(const std::string& array)
{
    vector<int> pv(array.size());
    for (int i=0; i<pv.size(); ++i)
    {
        pv[i] = i;
    }

    do { print (array, pv); } while (nextPermu(pv));
}

void do_nodup_permutation(const string& str, vector<bool>& used, string& current, int c)
{
    if (c == str.size())
    {
        std::cerr << current << std::endl;
        return;
    }

    const char* pre = NULL;
    for (int i=0; i<used.size(); ++i)
    {
        // I seperate the if statement, because the second part of the condition
        // is used to get ride of the duplicate permutation.
        // it is for future reference
        if (!used[i]
                && ( !pre || str[i] != *pre )) // this get ride of duplicated permutation
        {
            used[i] = true;
            current[c] = str[i];
            do_nodup_permutation(str, used, current, c+1);
            used[i] = false;
            pre = &str[i];

        }
    }
}

void do_normal_permutation( const string& str, vector<int>& indexes, int p )
{
    if (p == str.size())
    {
        print(str, indexes);
        return;
    }

    for (int i=0; i<str.size(); ++i)
    {
        if (isValid(indexes, p, i))
        {
            indexes[p] = i;
            do_normal_permutation(str, indexes, p+1);
        }
    }
}

void recursive_permutation( const string& str)
{
    std::cerr << "nodup:" << std::endl;
    vector<bool> used(str.size(), false);
    string current(str);
    do_nodup_permutation(str, used, current, 0);


    std::cerr << "normal one" << std::endl;
    vector<int> indexes(str.size());
    for (int i=0; i<indexes.size(); ++i)
    {
        indexes[i] = i;
    }
    do_normal_permutation(str, indexes, 0);
}


