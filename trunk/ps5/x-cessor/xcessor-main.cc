#include <iostream>
#include <vector>
#include <cstdlib>

#include "inputman.h"
#include "print.h"
#include "xcessor.h"


using namespace std;

int main(int argc, char *argv[])
{
    while(1)
    {
        try
        {
            vector<int> v;
            int x = Util::Read<int>();
            cout << x << endl;
            Util::ReadVector<int>(&v);
            Util::print(v);
            
            DS::TNode* tree = DS::MakeTree(v);
            DS::PrintLayer(tree);
            
            DS::TNode* p = predecessor(tree, x);
            cout << "pred: ";
            DS::PrintTNode(p); cout << endl;
            
            p = successor(tree, x);
            cout << "succ: ";
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
