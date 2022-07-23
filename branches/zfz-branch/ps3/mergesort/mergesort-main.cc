#include <stdexcept>
#include <cstdlib>

#include "inputman.h"
#include "print.h"
#include "mergesort.h"


using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        vector<int> a;

        try
        {
            Util::ReadVector<int>(&a);
    
            DS::LNode* l = DS::MakeList(a);
            DS::PrintList(l);
            cout << "sorted: ";
            l = rmergesortlist(&l, a.size());
            DS::PrintList(l);
            DS::FreeList(l);
            
            vector<int> b = a;
            //Util::print(b);
            cout << "sorted: ";
            rmergesort(b, 0, b.size()-1);
            Util::print(b);
            
            //Util::print(a);
            cout << "sorted: ";
            imergesort(a, 0, a.size()-1);
            Util::print(a);

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
