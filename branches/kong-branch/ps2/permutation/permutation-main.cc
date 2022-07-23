
/*

Print all the permutation of a given array (implement both iterative and recursive algorithms)

 */

#include <iostream>

#include "util.h"
#include "print.h"
#include "permutation.h"

int main(int argc, char * argv[]){
    std::cerr << "recusive for abc" << std::endl;
    std::cerr << "=============================" << std::endl;
    recursive_permutation( "abc" );
    std::cerr << "=============================" << std::endl;
    recursive_permutation( "aa" );
    std::cerr << "=============================" << std::endl;
    std::cerr << std::endl << std::endl;


    std::cerr << "iterative for abc" << std::endl;
    std::cerr << "=============================" << std::endl;
    ipermu( "abc" );
    std::cerr << "=============================" << std::endl;
    std::cerr << std::endl << std::endl;

    std::cerr << "iterative with next permutation for abc" << std::endl;
    std::cerr << "=============================" << std::endl;
    ipermu_next( "abc" );
    std::cerr << "=============================" << std::endl;
    ipermu_next( "aa" );
    std::cerr << "=============================" << std::endl;
    std::cerr << std::endl << std::endl;


    std::cerr << "next permutation for duplicated elements " << std::endl;
    vector<int> v(4);
    v[0] = 0; v[1] = 1; v[2] = 1; v[3] = 2;
    
    while (nextPermu(v) )
    {
        for ( int i=0; i<v.size(); ++ i )
            std::cerr << v[i];
        std::cerr << std::endl;
    }
    
}

