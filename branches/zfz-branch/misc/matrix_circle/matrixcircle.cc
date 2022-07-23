#include <iostream>
#include <cstdlib>
#include <iomanip>


using namespace std;

int** init(int r, int c)
{
    srand(0);
    int** m = new int*[r];
    for (int i = 0; i < r; ++i)
    {
        m[i] = new int[c];
        for (int j = 0; j < c; ++j)
        {
            m[i][j] = rand() % 100;
        }
    }
    return m;
}

void print(int** m, int r, int c)
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout << setw(3) << m[i][j];
        }
        cout << endl;
    }
}



void print(int** m, int* x, int* y, int len, int d, int e)
{
    if (len <= 0) { return; }
    int* r = (d == 0) ? x : y;
    for (int i = 0; i < len; ++i)
    {
        *r += e;
        cout << setw(3) << m[*x][*y];
    }
}

void print_circle(int** m, int r, int c)
{
    int x = 0, y = -1, e = 1;
    while (r > 0 && c > 0)
    {
        print(m, &x, &y, c--, 1, e);
        print(m, &x, &y, --r, 0, e);
        e = -e;
    }
    cout << endl;
}

