#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int dime,i,r,verifpal;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	r=dime-1; verifpal=0;
	int source[dime];
	int dest[dime];
	for (i=0; i<dime; i++)
	{
		cout <<"inserire il valore numero " <<i <<endl;
		cin >>source[i];
	}
	for (i=0; i<dime; i++) 
	{
		dest[r]=source[i];
		r--;
	}
	for (i=0; i<dime; i++) 
	{
		if (dest[i]==source[i]) verifpal++;
	}
	if (verifpal==dime)
	cout <<"array palindromo\n";
	else cout <<"array non palindromo\n";
}