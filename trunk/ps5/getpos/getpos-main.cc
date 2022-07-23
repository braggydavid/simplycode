#include <vector>
#include <cstdlib>
#include <iostream>

#include "getpos.h"
#include "inputman.h"
#include "print.h"


using namespace std;
using namespace DS;


int main(int argc, char *argv[])
{
    while(1)
    {
        try
        {
            vector<int> v;
            int x = Util::Read<int>();
            Util::print(x);
            Util::ReadVector<int>(&v);
            Util::print(v);
            
            DS::TNode* tree = DS::MakeTree(v);

            cout << "In order: ";
            DS::PrintInOrder(tree);
            
            cout << "pos: " << getpos(tree, x) << endl;
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
