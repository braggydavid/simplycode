#include <stdexcept>
#include <cstdlib>

#include "intreverse.h"
#include "inputman.h"
#include "print.h"

using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        try
        {
            int a = Util::Read<int>();
            Util::printbinary(a); cout << endl;
            int c = binaryreverse((uint)a);
            Util::printbinary(c); cout << endl;

            Util::print(a);
            int b = intreverse(a);
            Util::print(b);

            cout << "---" << endl;
        }
        catch (const char *e)
        {
            break;
        }
        catch (const runtime_error& e)
        {
            cerr << e.what() << endl;
        }
        catch (...)
        {
            cerr << "unknown error" << endl;
            exit(1);
        }

        
    }
    return 0;
}
