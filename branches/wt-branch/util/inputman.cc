#include "inputman.h"

namespace Util
{

void tokenize(std::vector<std::string> *pv, 
              const std::string &line, 
              const char delim)
{
    if (pv == NULL)
    {
	throw std::runtime_error("tokenize(): dest vector null.");
    }

    int start = 0, len = 0;
    for (int i = 0; i < line.length(); ++i)
    {
	if (len == 0) { start = i; }
	
	if (line.at(i) == delim)
	{
	    pv->push_back(line.substr(start, len));
	    len = 0;
	}
	else
	{
	    ++ len;
	}
    }
    pv->push_back(line.substr(start, len));
}

} // namespace Util
