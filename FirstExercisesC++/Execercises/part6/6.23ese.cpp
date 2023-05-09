#include <iostream>
#include <string>
#include <math.h>
using namespace std;

float evaporatore(float l, int d, float lmin);

int main()
{
	float litri,litrimin,gg;
	int perc;
	cout <<"numero di litri inseriti: \n";
	cin >>litri;
	cout <<"percentuale di evaporazione: \n";
	cin >>perc;
	cout <<"soglia minnima in litri: \n";
	cin >>litrimin;
	gg=evaporatore(litri, perc, litrimin);
	cout <<"numero di giorni: " <<gg <<endl;
}

float evaporatore(float l, int d, float lmin)
{
	float conta;
	conta=0;
	while (lmin<=l)
	{
		
		l=l-l*d/2400.0;
		conta++;
	}
	conta=conta/24;
	return(conta);
}