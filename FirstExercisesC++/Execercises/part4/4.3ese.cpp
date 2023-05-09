#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int i,n; 
	i=0; n=10;
	int firstarray[n];
	float secondarray[n];
	for (i; i<n; i++) 
	{
		cout <<"inserire valore n." <<i <<endl;
		cin >>firstarray[i];
	}
	for (i=0; i<n; i++) 
	{
		cout <<"inserire valore n." <<i <<"del secondo array float\n";
		cin >>secondarray[i];
	}
	for (i=0; i<n; i++) 
	{
		cout <<firstarray[i] <<endl;
		cout <<secondarray[i] <<endl;
	}
}