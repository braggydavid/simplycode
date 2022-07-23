#ifndef INCLUDED_PHONEWORDS_H
#define INCLUDED_PHONEWORDS_H

#include <vector>
#include <string>
#include <map>

class NumericDictionary
{
public:
    NumericDictionary(const std::vector<std::string>& words);
    std::vector<std::string> getMatchedWords(const int& num);
    
private:
    static const int alphabet[];
    std::map<int,std::vector<std::string> > num2words;
};

#endif // INCLUDED_PHONEWORDS_H
