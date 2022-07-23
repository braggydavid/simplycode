#include <iostream>
#include "rotatevector.h"

using namespace std;


int main()
{
    string str("abcdefghi");
    cout << "origional: " << str << endl;
    
    for ( int i=0; i<20; ++i )
    {
        string c(str);
        rotatevector(c, i);
        cout << i << ": " << c << endl;
    }

    return 0;
}
