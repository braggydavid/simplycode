#include <iostream>
#include "wordreverse.h"

using namespace std;

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line))
    {
        cout << "     original: " << line << endl;
        
        wordreverse(line);
        cout << "  wordreverse: " << line << endl;
        
        wordreverse(line); // restore to original
        stringreverse(line);
        cout << "stringreverse: " << line << endl;
                
        cout << "---" << endl;
    }

    return 0;
}
