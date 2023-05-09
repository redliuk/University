#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	
	int dime,copia,max,min,pmax;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	int source[dime];
	int dest[dime];
	for (int conta=0; conta<dime; conta++)
	{
		cout <<"inserire il valore intero numero " <<conta <<endl;
		cin >>source[conta];
	}
	max=source[0]; min=source[0];
	for (int conta=0; conta<dime; conta++) 
		{
			if (source[conta]<min)
				{
					min=source[conta];
				}
		}
	for(int copia=dime-1; copia>=0; copia--)
	{
		for (int conta=0; conta<dime; conta++) 
		{
			if (source[conta]>=max)
				{
					max=source[conta];
					pmax=conta;
				}
		}
		dest[copia]=max;
		max=min;
		source[pmax]=min;
	}
	cout <<endl <<"array dest: ";
	for (int conta=0; conta<dime; conta++)
	{
		cout  <<dest[conta] <<" ";
	}
	cout <<endl;
}