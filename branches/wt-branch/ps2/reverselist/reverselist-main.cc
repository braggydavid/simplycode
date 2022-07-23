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
    
        ST::LNode* l = ST::MakeList(v);
        
        ST::PrintList(l);
        l = ireverse(l);
        ST::PrintList(l);
        
        l = rreverse(l, NULL);
        ST::PrintList(l);
        
        ST::FreeList(l);

        cout << "---" << endl;
    }
    
    return 0;
}
