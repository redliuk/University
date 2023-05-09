#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int a,copia,i,p,som,first;
	som=0; i=0;
	cout <<"inserire un valore intero positivo\n";
	cin >>a;
	copia=a;
	for (i; copia>0; i++) copia=copia/10;
	copia=a;
	for (p=1; p<=i; p++)
	{	
		first=copia/pow(10,i-p);
		som=som+pow(first,i);
		copia=copia-first*pow(10,i-p);
	}
	if (som==a) cout <<"il valore dato è un numero di amstrong!\n";
	else cout <<"il valore dato non è un numero di amstrong\n";
}