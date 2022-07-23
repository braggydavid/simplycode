#include <stdexcept>
#include <cstdlib>

#include "inputman.h"
#include "print.h"
#include "rectangle.h"



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
            
            cout << rectangle(v) << endl;
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
