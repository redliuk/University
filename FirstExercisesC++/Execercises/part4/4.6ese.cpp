#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int dime,i,copia,ripe,max;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	int array[dime];
	for (i=0; i<dime; i++)
	{
		cout <<"inserire il valore numero " <<i <<endl;
		cin >>array[i]; 
	}
	max=array[0]; ripe=0;
	for (i=0; i<dime; i++) 
	{
		if (array[i]>max)	max=array[i];
	}
	for (i=0; i<dime; i++)
	{
		if (array[i]==max)	ripe++;
	}
	cout <<"il valore maggiore dell'array è: " <<max <<endl;
	cout <<"il valore più alto ha " <<ripe <<" occorenze\n";
}