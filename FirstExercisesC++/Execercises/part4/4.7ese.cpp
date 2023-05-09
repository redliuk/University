#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int dime,i,copia,pari,dispari;
	pari=0; dispari=0;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	int array[dime];
	for (i=0; i<dime; i++)
	{
		cout <<"inserire il valore numero " <<i <<endl;
		cin >>array[i]; 
	}
	for (i=0; i<dime; i++)
	{
		if (array[i]%2==0) pari++;
	}
	dispari=dime-pari;
	cout <<"i numeri pari sono: " <<pari <<endl;
	cout <<"i numeri dispari sono: " <<dispari <<endl;
}