#include <string>
#include <iostream>
#include "phonewords.h"

using namespace std;

const int NumericDictionary::alphabet[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

NumericDictionary::NumericDictionary(const vector<string>& words)
{
    for (int i = 0; i < words.size(); i++)
    {
        string::const_iterator it;
        int num = 0;
        for (it = words[i].begin(); it < words[i].end(); it++)
        {
            num = 10*num+alphabet[toupper(*it)-'A'];
        }
        num2words[num].push_back(words[i]);
    }
}

vector<string> NumericDictionary::getMatchedWords(const int& num)
{
    return num2words[num];
}
