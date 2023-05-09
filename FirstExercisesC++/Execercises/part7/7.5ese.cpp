#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int n,d; 
	n=10; 
	float som=0;
	int secondarray[n];
	int *p=secondarray;
	for (int i=0; i<n; i++) 
	{
		cout <<"inserire valore n." <<i <<endl;
		cin >>d;
		*(p+i)=d;
	}
	p=secondarray;
	for (int i=0; i<n; i++) 
	{
		som=som+*(p+i);
	}
	cout <<"la media dei valori inseriti risulta: " <<som/n <<endl;
}