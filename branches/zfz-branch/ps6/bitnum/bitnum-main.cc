#include <iostream>
#include <cstdlib>

#include "inputman.h"
#include "print.h"
#include "bitnum.h"


using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        try
        {
            uint x = Util::Read<int>();
            cout << "  input: " << x << " -> ";
            Util::printbinary(x);
            cout << endl;
            uint y = x;
            if (bitnum(x, 1))
            {
                cout << " larger: " << x << " -> ";
                Util::printbinary(x);
                cout << endl;
            }
            else
            {
                cout << " no larger number" << endl;
            }
            
            x = y;
            if (bitnum(x, 0))
            {
                cout << "smaller: " << x << " -> ";
                Util::printbinary(x);
                cout << endl;
            }
            else
            {
                cout << "no smaller number" << endl;
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
