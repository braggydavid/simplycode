#include <cstdlib>
#include <vector>

#include "inputman.h"
#include "reverselist.h"

using namespace std;


int main(int argc, char *argv[])
{

    vector<int> v;
    
    while (1)
    {
        v.clear();
        try
        {
            Util::ReadVector<int>(&v);
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
    
        DS::LNode* l = DS::MakeList(v);
        
        DS::PrintList(l);
        l = ireverse(l);
        DS::PrintList(l);
        
        l = rreverse(l, NULL);
        DS::PrintList(l);

        rreverse(&l);
        DS::PrintList(l);
        
        DS::FreeList(l);

        cout << "---" << endl;
    }
    
    return 0;
}
