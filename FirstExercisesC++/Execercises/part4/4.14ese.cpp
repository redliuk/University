#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	
	int dime,copia,conta,scamb,pmax;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	int source[dime];
	for (conta=0; conta<dime; conta++)
	{
		cout <<"inserire il valore intero numero " <<conta <<endl;
		cin >>source[conta];
	}
	for (copia=0; copia<dime; copia++)
	{ 
		for (conta=0; conta<dime; conta++)
			if (source[conta+1]<=source[conta])
			{
				scamb=source[conta];
				source[conta]=source[conta+1];
				source[conta+1]=scamb;
			}
	}
	for (conta=0; conta<dime; conta++)
	{
		cout <<source[conta] <<" ";
	}
	cout <<endl;
}