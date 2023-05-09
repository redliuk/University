#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() 
{
	int b,a,conta;
	conta=0;
	cout <<"inserire quanti valori conterrà l'array: " <<endl;
	cin >>b;
	int x[b];
	int i,l;
	cout <<"inserire valori primo array: " <<endl;
	for (i=0; i<b; i++) 
	{
		cin >>a;
		x[i]=a;
	}
	for (i=0; i<b-conta-1; i++)	//ripeti finchè non è raggiunta la dimensione meno 1 tolto il numero di										ripetizioni
	{
		while (x[i]==x[i+1]) //finchè il precedente è uguale al successivo
		{
			l=i;				//a partire dal punto dove trovo la ripetizione
			while (l<b-conta)	// finchè non raggiungo la dime meno il numero di ripetizioni
			{
				x[l]=x[l+1];	//scartando il precedente sposta tutti a sinistra
				l++;
				x[b]=0; //poni l'ultimo elemento uguale a 0
			}
		conta++;	//aumento il numero di ripetizioni trovato di uno
		}
	}
	cout <<"i valori dell'array ora sono: " <<endl;
	for (i=0; i<b; i++)		cout <<x[i] <<" ";
	cout <<endl;
}