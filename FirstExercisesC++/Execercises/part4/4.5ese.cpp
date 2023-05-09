#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int i,j,n;
	float a;
	n=10; j=0;
	float firstarray[n];
	for (j; j<n; j++)
	{
		firstarray[j]=n-j;
	}
	cout <<"inserire un valore intero compreso tra 0 e " <<n <<endl;
	cin >>i;
	a=(i*i)/2;
	firstarray[i]=a;
	for (j=0; j<n; j++)
	{
		cout <<firstarray[j] <<endl;
	}
}