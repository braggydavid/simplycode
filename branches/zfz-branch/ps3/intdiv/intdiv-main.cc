#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "intdiv.h"
#include "inputman.h"


using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        try
        {
            uint x = Util::Read<uint>();
            uint y = Util::Read<uint>();     
            cout << x << "/" << y << "=";
            cout << intdiv(x, y) << endl;
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
