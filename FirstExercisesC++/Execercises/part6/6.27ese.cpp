#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int sommaDividendi(int a, int b, int max);

int main()
{
	int a,b,max,somma;
	cout <<"inserier il primo valore intero e positivo:\n";
	cin >>a;
	while (a<0)
	{
	cout <<"errore: numero negativo\n" <<"ripetere inserimento: \n";
	cin >>a;
	}
	cout <<"inserier il secondo valore intero e positivo:\n";
	cin >>b;
	while (b<0)
	{
	cout <<"errore: numero negativo\n" <<"ripetere inserimento: \n";
	cin >>b;
	}
	cout <<"inserier il valore intero positivo del massimo della somma:\n";
	cin >>max;
	while (max<0)
	{
	cout <<"errore: numero negativo\n" <<"ripetere inserimento: \n";
	cin >>max;
	}
	somma=sommaDividendi(a,b,max);
	cout <<"la somma dei divisori risulta: " <<somma <<endl;
}

int sommaDividendi(int a, int b, int max)
{
	int somma;
	for (int conta=0; conta<=max; conta++)
	{
		if (conta%a==0 || conta%b==0)
		{
			somma=somma+conta;
		}
	}
	return(somma);
}