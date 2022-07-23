// simplecode.cpp : main project file.
#include "rotatevector.h"
using namespace std;

void print(vector<char> *eles){
	for(int  i=0;i<eles->size();i++){
		cout << (*eles)[i] <<" ";
	}
	cout << endl;
}
void reverse(vector<char> *elements, int start, int end){
	while(start<end){
		char temp=(*elements)[start];
		(*elements)[start]=(*elements)[end];
		(*elements)[end]=temp;
		start++;
		end--;
	}
}

void rotate(vector<char> *elements, int i){
	i %= elements->size();
	reverse(elements, 0, i-1);
	reverse(elements, i, elements->size()-1);
	reverse(elements, 0, elements->size()-1);
}
