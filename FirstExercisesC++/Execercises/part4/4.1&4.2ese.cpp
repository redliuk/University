#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int i,n; 
	i=0; n=8;
	int firstarray[8];
	float secondarray[8];
	for (i; i<8; i++) 
	{
		firstarray[i]=n;
		secondarray[i]=n;	
		n=n-1;
	}
	for (i=0; i<8; i++) 
	{
		cout <<firstarray[i] <<endl;
	}
	for (i=0; i<8; i++) 
	{
		cout <<secondarray[i] <<endl;	
	}
}