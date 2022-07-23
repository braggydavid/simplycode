#include <iostream>
#include <cstdlib>

#include "anagram.h"
#include "inputman.h"
#include "print.h"


using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        try
        {
            vector<string> v;
            Util::ReadVector<string>(&v);
            Util::print(v);
            
            vector<vector<string> > r = anagram(v);
            for (int i = 0; i < r.size(); ++i)
            {
                cout << "-> "; Util::print(r[i]);
            }
            cout << "---" << endl;
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
