#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	
	int dime,copia,conta;
	float scamb;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	float source[dime];
	int dest[dime];
	copia=dime/2;
	for (conta=0; conta<dime; conta++)
	{
		cout <<"inserire il valore intero numero " <<conta <<endl;
		cin >>source[conta];
	}
	for (conta=0; conta<copia; conta++)
	{
		scamb=source[conta];
		source[conta]=source[dime-1-conta];
		source[dime-1-conta]=scamb;
	}
	for (conta=0; conta<dime; conta++)
	{
		cout <<source[conta] <<" ";
	}
	cout <<endl;
}			