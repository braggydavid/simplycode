#include <stdexcept>
#include <cstdlib>

#include "unipermu.h"
#include "inputman.h"
#include "print.h"

using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        vector<int> a;

        try
        {
            Util::ReadVector<int>(&a);
            Util::print(a);
            
            cout << "unipermu1:" << endl;
            unipermu1(a);
            
            cout << "unipermu2:" << endl;
            unipermu2(a);

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
