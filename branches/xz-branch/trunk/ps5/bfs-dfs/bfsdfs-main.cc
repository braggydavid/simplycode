#include <vector>
#include <cstdlib>
#include <iostream>

#include "bfsdfs.h"
#include "inputman.h"
#include "print.h"


using namespace std;

int main(int argc, char *argv[])
{
    while(1)
    {
        try
        {
            vector<int> v;
            Util::ReadVector<int>(&v);
            Util::print(v);
            
            DS::TNode* tree = DS::MakeTree(v);
            DS::PrintLayer(tree);
            
            bfs(tree);  cout << endl;
            rdfs(tree); cout << endl;
            idfs(tree); cout << endl;

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
