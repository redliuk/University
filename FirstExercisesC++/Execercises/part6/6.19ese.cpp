#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

bool numeroArmstrong(int a);

int main()
{
	int x;
	cout <<"inserire un valore intero positivo\n";
	cin >>x;
	if (numeroArmstrong(x)) cout <<"il valore dato è un numero di armstrong!\n";
	else cout <<"il valore dato non è un numero di armstrong\n";
}

bool numeroArmstrong(int a)
{
	int copia,i,p,som,first;
	som=0; i=0;
	copia=a;
	for (i; copia>0; i++) copia=copia/10;
	copia=a;
	for (p=1; p<=i; p++)
	{	
		first=copia/pow(10,i-p);
		som=som+pow(first,i);
		copia=copia-first*pow(10,i-p);
	}
	return(som==a);
}