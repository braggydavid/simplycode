#ifndef INCLUDED_INPUTMAN
#define INCLUDED_INPUTMAN

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <climits>
#include <stdexcept>

namespace Util
{

template <class T>
T Read()
{
    T t;
    std::cin >> t;
    
    if (std::cin.eof())
    {
        throw "EOF";
    }
    
    if (std::cin.bad() || std::cin.fail())
    {
        throw std::runtime_error("** Read() error.");
    }
    
    std::cin.ignore(INT_MAX, '\n');

    return t;
}

template <typename T>
T fromStr (const std::string& s)
{
    std::istringstream iss(s);
    T t;
    iss >> t;
    if (iss.fail())
    {
	throw std::runtime_error("fromStr(): Error parsing \"" + s + "\".");
    }
    iss >> std::ws;
    if (iss.eof())
    {
	return t;
    }
    throw std::runtime_error("fromStr(): Error parsing \"" + s + "\".");
}

void tokenize(std::vector<std::string> *pv, 
              const std::string &line, 
              const char delim='|');

template <class T>
void ReadVector(std::vector<T> *v)
{
    if (!v) { throw "null input vector"; }

    std::string line;
    std::getline(std::cin, line);

    if (std::cin.eof())
    {
        throw "EOF";
    }

    if (std::cin.bad() || std::cin.fail())
    {
        throw std::runtime_error("** Read() error.");
    }

    
    std::vector<std::string> vs;
    tokenize(&vs, line);

    for (int i = 0; i < vs.size(); ++i)
    {
      v->push_back(fromStr<T>(vs[i]));
    }
}

} // namespace Util

#endif /* INCLUDED_INPUTMAN */
