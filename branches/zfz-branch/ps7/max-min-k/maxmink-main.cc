#include <stdexcept>
#include <cstdlib>

#include "inputman.h"
#include "print.h"
#include "maxmink.h"



using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        try
        {
            vector<int> v;
            Util::ReadVector<int>(&v);
            Util::print(v);
            
            for (int k = 1; k < v.size(); ++k)
            {
                cout << "k = " << k << ", maxmink1(): " << maxmink1(v, k) << endl;
                cout << "k = " << k << ", maxmink2(): " << maxmink2(v, k) << endl;
                cout << "k = " << k << ", maxmink3(): " << maxmink3(v, k) << endl;
                cout << "---" << endl;
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

