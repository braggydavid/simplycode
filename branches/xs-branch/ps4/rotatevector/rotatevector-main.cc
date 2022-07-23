#include "rotatevector.h"

int main()
{
    
    for ( int i=0; i<10; ++i )
    {
        vector<char> eles;	
	for(int j=0;j<7;++j){
	   eles.push_back('a'+j);	
	}
	cerr << "origional: " ;
	print(&eles) ;
        rotate(&eles, 3);
	cerr << "rotated: " ;
	print(&eles) ;
    }

    return 0;
}
