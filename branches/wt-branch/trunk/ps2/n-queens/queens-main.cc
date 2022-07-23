#include <iostream>
#include <vector>
#include "queens.h"

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    vector<int> p(n,0);
    
    int count = 0;
    cout << "Recursively backtracking:" << endl;
    rsolve(p,0,count);
    cout << "The number of solutions are " << count << endl;

    count = 0;
    cout << "Iteratively backtracking:" << endl;
    isolve(p,count);
    cout << "The number of solutions are " << count << endl;

    return 0;
}
