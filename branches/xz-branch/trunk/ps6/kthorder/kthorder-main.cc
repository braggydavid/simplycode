#include <iostream>

#include "inputman.h"
#include "kthorder.h"

using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        int k;
        vector<int> a;
	
        try
        {
            cout << "Input k:";
            k = Util::Read<int>();
            cout << "Input array:" << endl;
            Util::ReadVector<int>(&a);
	
            // solution 1
            int r1 = kthnum(a, 0, a.size()-1, k);

            // solution 2
            int r2 = kthorder(a, k);

            cout << r1 << " " << r2 << endl;
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
