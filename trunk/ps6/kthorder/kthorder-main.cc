#include <iostream>
#include <cstdlib>

#include "inputman.h"
#include "kthorder.h"
#include "print.h"



using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        try
        {
            int k = Util::Read<int>();
            Util::print(k);
            vector<int> a;
            Util::ReadVector<int>(&a);
            Util::print(a);
	
            // solution 1
            int r1 = kthnum(a, 0, a.size()-1, k);

            // solution 2
            int r2 = kthorder(a, k);
            
            cout << "  kthnum(): " << r1 << endl;
            cout << "kthorder(): " << r2 << endl;
            cout << "---" << endl;
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
