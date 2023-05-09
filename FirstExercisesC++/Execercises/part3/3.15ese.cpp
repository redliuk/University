#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	double a,b;
	cout <<"inserire un valore positivo\n";
	cin >>a;
	cout <<"prova a indovinarne la radice quadrata\n";
	cin >>b;
	do
	{
		if (sqrt(a)==b)
		{
			cout <<"Bravo!" <<endl;
			return(0);
		}
		cout <<"riprova\n";
		cin >>a;
	}
	while (sqrt(a)!=b);
}