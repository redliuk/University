#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	
	int dime,conta,conta2;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	int source[dime];
	int dest[dime];
	conta2=0;
	for (conta=0; conta<dime; conta++)
	{
		cout <<"inserire il valore intero numero " <<conta <<endl;
		cin >>source[conta];
	}
	for (conta=0; conta<dime; conta++)
	{
		dest[conta]=0;
	}
	for (conta=0; conta<dime; conta++)
	{
		if (source[conta]==source[conta+1] && dest[conta2-1]!=source[conta])
			{
				dest[conta2]=source[conta];
				conta2++;
			}
		if (source[conta]!=source[conta+1] && dest[conta2-1]!=source[conta])
		{
			dest[conta2]=source[conta];
			conta2++;
		}
	}
		for (conta=0; conta<dime; conta++)
	{
		cout <<dest[conta] <<" ";
	}
	cout <<endl;
	for (conta=0; conta<dime; conta++)
	{
		source[conta]=0;
	}
	for (conta=0; conta<dime; conta++)
	{
		source[conta]=source[conta]+dest[conta];
	}
	for (conta=0; conta<dime; conta++)
	{
		cout <<source[conta] <<" ";
	}
	cout <<endl;
}			