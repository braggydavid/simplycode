#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "inputman.h"
#include "print.h"
#include "lis.h"

using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        vector<int> v;
        
        try
        {
            Util::ReadVector<int>(&v);
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
    
        cout << "lis0 : " << lis0(v) << endl;
        cout << "lis1 : " << lis1(v) << endl;
        
        list<int> l;
        lis2(v, &l);
        cout << "lis2 : " << l.size() << " -> ";
        
        Util::print(l);
        
        cout << "---" << endl;
    }

    return 0;
}
