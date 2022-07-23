#include "miniwindow.h"

int main()
{
    int window = miniwindow("a brilliant cat is eating a big cake", "abc");
    cerr << "Window: " << window << endl;
    window = miniwindow("a brilliant cat is eating a big cake", "abcz");
    cerr << "Window: " << window << endl;

    return 0;
}
