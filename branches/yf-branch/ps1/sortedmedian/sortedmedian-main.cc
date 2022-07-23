#include <iostream>
#include <cstdlib>

#include "inputman.h"
#include "sortedmedian.h"

using namespace std;

int main(int argc, char *argv[])
{

    while (1)
    {
        vector<int> a, b;
        
        try
        {
            Util::ReadVector<int>(&a);
            Util::ReadVector<int>(&b);

            int m1 = median(a,b);
            int m2 = getmedian(a,b);

            cout << m1 << " : " << m2 << endl;
        }
        catch(const char *e)
        {
            break;
        }
        catch(const runtime_error &e)
        {
            cerr << e.what() << endl;
            exit(1);
        }
        catch(...)
        {
            cerr << "unknown error" << endl;
            exit(1);
        }
    }

    return 0;
}
