#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	float s;
	int i,n; 
	i=0; n=10; s=0;
	float secondarray[n];
	for (i=0; i<n; i++) 
	{
		cout <<"inserire valore n." <<i <<endl;
		cin >>secondarray[i];
	}
	for (i=0; i<n; i++) 
	{
		s=s+secondarray[i];
	}
	cout <<"la media dei valori inseriti risulta: " <<s/n <<endl;
}