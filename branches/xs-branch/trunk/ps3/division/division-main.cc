
#include "division.h"
#include <iostream>

#include "inputman.h"

using namespace std;

int main()
{
    while (1)
    {
        try
        {
            std::cerr << "test: " << std::endl;
            uint x = Util::Read<uint>();
            uint y = Util::Read<uint>();
            cout << x << "/" << y << "=" << std::endl;;
            cout << "\t" << uintdiv1(x, y) << endl;
            cout << "\t" << uintdiv2(x, y) << endl;
            cout << "============" << endl;
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


