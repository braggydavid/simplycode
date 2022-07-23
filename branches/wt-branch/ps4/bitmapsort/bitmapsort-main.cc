#include <stdexcept>
#include <cstdlib>

#include "inputman.h"
#include "print.h"
#include "bitmapsort.h"


using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        vector<int> number;

        try
        {
            Util::ReadVector<int>(&number);
            cout << "before: ";
            Util::print(number);
            bitmapsort(number);
            cout << "after:  ";
            Util::print(number);
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
