#include <iostream>

#include "randgen.h"
#include "util.h"
#include "sortedsum.h"

using namespace std;

int main(int argc, char *argv[])
{
    RandGen g;

    int s[] = {3, 8, 16, 31, 65, 128};
    
    for (int i = 0; i < sizeof(s)/sizeof(s[0]); ++i)
    {
        int n = s[i];
        
        vector<int> array;
        g.GetSortedRandVector(&array, n);
        
        int sum = g.GetRand();

        Util::print( array );
        Util::print(sum);

        cout << "Found sum of 2? " << has2sum(array, sum ) << endl;
        vector<pair<int, int> > pairs = get2sum(array, sum); 
        for (int j = 0; j < pairs.size(); ++j)
        {
            cerr << pairs[j].first << " + " << pairs[j].second << " = " << sum << endl;
        }
        cout << "Found sum of 3? " << has3sum(array, sum ) << endl;
        cout << "---" << endl;
    }
    return 0;
}
