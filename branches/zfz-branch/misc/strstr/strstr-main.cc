#include <stdexcept>
#include <iostream>
#include <cstring>

#include "strstr.h"


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
            const char* p = strstr1(s1.c_str(), s2.c_str());
            if (p != NULL)
            {
                cout << "strstr1(): " << p << endl;
            }
            else
            {
                cout << "strstr1(): NULL" << endl;
            }
            
            p = strstr(s1.c_str(), s2.c_str());
            if (p != NULL)
            {
                cout << " strstr(): " << p << endl;
            }
            else
            {
                cout << " strstr(): NULL" << endl;
            }
        }
        catch (const runtime_error& e)
        {
            cout << e.what() << endl;
        }
        
        cout << "---" << endl;
    }
    
    return 0;
}
