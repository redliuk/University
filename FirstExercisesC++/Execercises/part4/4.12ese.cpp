#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int dime,conta,max;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	int source[dime];
	for (conta=0; conta<dime; conta++)
	{
		cout <<"inserire il valore intero numero " <<conta <<endl;
		cin >>source[conta];
	}
	max=source[0];
	for (conta=0; conta<dime; conta++) 
	{
		if (source[conta]>max)	max=source[conta];
	}
	max=max-1;
	cout <<"il secondo valore più elevato è: " <<max <<endl;
}
