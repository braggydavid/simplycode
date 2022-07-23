#include <stdexcept>
#include <cstdlib>

#include "intersect.h"
#include "inputman.h"
#include "print.h"

using namespace std;

int main(int argc, char *argv[])
{
    while (1)
    {
        vector<int> a, b, c;

        try
        {
            Util::ReadVector<int>(&a);
            Util::ReadVector<int>(&b);

            Util::print(a);
            Util::print(b);

            cout << "intersect: ";
            c = intersect(a,b);
            Util::print(c);
            cout << "unify    : ";
            c = unify(a,b);
            Util::print(c);
            cout << "minus    : ";
            c = substract(a,b);
            Util::print(c);
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
