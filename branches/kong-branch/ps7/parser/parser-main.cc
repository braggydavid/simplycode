#include "parser.h"

int main()
{
    parser("4 + 2*16/8 - 3");
    parser("4 + 2+16-8 - 3");
    parser("4 + 2*16/0 - 3");

    return 0;
}
