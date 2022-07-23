#include <iostream>
#include <cstdlib>

#include "inputman.h"
#include "print.h"
#include "construct.h"


using namespace std;

int main(int argc, char *argv[])
{
    while(1)
    {
        try
        {
            vector<int> a, b;
            Util::ReadVector<int>(&a);
            Util::ReadVector<int>(&b);
            Util::print(a);
            Util::print(b);

            DS::TNode* t1 = construct(a, 0, b, 0, a.size());
            DS::TNode* t2 = construct(a, 0, a.size());
            
            DS::PrintPreOrder(t1);
            DS::PrintInOrder(t1);
            
            DS::PrintPreOrder(t2);            
            DS::PrintInOrder(t2);
            
            DS::DestroyTree(t1);
            DS::DestroyTree(t2);
            
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
