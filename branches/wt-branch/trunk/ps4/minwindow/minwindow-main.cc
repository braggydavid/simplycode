#include <iostream>
#include <cstdlib>

#include "inputman.h"
#include "minwindow.h"


using namespace std;

int main(int argc, char *argv[])
{
    string text, word;
    while (getline(cin, text) && getline(cin, word))
    {
        cout << "Text: " << text << endl;
        cout << "Word: " << word << endl;
        
        cout << "minwindow1: " << minwindow1(text, word) << endl;
        cout << "minwindow2: " << minwindow2(text, word) << endl;
        
        cout << "---" << endl;
    }

    return 0;
}
