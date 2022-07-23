#include <iostream>
#include <cstdlib>

#include "inputman.h"
#include "print.h"
#include "lcp.h"


using namespace std;

int main(int argc, char* argv[])
{
    while(1)
    {
        try
        {
            vector<int> v;
            int x = Util::Read<int>();
            int y = Util::Read<int>();
            
            cout << x << ", " << y << endl;
            Util::ReadVector<int>(&v);
            Util::print(v);
            
            DS::TNode* tree = DS::MakeTree(v);
            DS::PrintLayer(tree);
            
            DS::TNode* p = NULL;
            lcp(tree, x, y, &p);
            DS::PrintTNode(p); cout << endl;
            
            p = NULL;
            rbst_lcp(tree, x, y, &p);
            DS::PrintTNode(p); cout << endl;

            p = NULL;
            ibst_lcp(tree, x, y, &p);
            DS::PrintTNode(p); cout << endl;
            
            DS::DestroyTree(tree);
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
