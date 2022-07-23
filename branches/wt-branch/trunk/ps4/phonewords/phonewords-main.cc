#include <stdexcept>
#include <cstdlib>

#include "inputman.h"
#include "print.h"
#include "phonewords.h"


using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        vector<int> number;
        vector<string> dictionary;
        vector<string> matchedWords;

        try
        {
            Util::ReadVector<int>(&number);
            Util::ReadVector<string>(&dictionary);
            NumericDictionary ndict(dictionary);
            for (int i = 0; i < number.size(); i++)
            {
                matchedWords = ndict.getMatchedWords(number[i]);
                cout << "Matched words for " << number[i] << ": ";
                if (matchedWords.empty())
                {
                    cout << "N/A" << endl;
                }
                else
                {
                    Util::print(matchedWords);
                }
            }
        }
        catch (const char *e)
        {
            break;
        }
        catch (const runtime_error& e)
        {
            cerr << e.what() << endl;
            exit(1);
        }
        catch (...)
        {
            cerr << "unknown error" << endl;
            exit(1);
        }
    }

    return 0;
}
