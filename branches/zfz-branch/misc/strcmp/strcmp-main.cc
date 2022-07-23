#include <stdexcept>
#include <iostream>
#include <cstring>

#include "strcmp.h"


using namespace std;

int main(int argc, char *argv[])
{
    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2))
    {
        cout << "s1: " << s1 << endl;
        cout << "s2: " << s2 << endl;
        
        try
        {
            int x = strcmp1(s1.c_str(), s2.c_str());
            cout << "strcmp1(): " << x << endl;
            x = strcmp2(s1.c_str(), s2.c_str());
            cout << "strcmp2(): " << x << endl;
            x = strcmp(s1.c_str(), s2.c_str());
            cout << " strcmp(): " << x << endl;
        }
        catch (const runtime_error& e)
        {
            cout << e.what() << endl;
        }
        
        cout << "---" << endl;
    }
    
    return 0;
}
