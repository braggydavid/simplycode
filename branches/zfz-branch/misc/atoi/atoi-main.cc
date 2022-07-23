#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "atoi.h"


using namespace std;

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line))
    {
        cout << "   line: " << line << endl;
        
        try
        {
            int x = atoi(line.c_str());
            cout << " atoi(): " << x << endl;

            x = atoi1(line.c_str());
            cout << "atoi1(): " << x << endl;

            x = atoi2(line.c_str());
            cout << "atoi2(): " << x << endl;
        }
        catch (const runtime_error& e)
        {
            cout << e.what() << endl;
        }
        
        cout << "---" << endl;

    }


    return 0;
}
