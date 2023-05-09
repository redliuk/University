#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

bool controlloRadice(double x,double sqrt_x);

int main()
{
	double a,b;
	cout <<"inserire un valore positivo\n";
	cin >>a;
	cout <<"prova a indovinarne la radice quadrata\n";
	cin >>b;
	if (controlloRadice(a,b)) cout <<"radice corretta\n";
	else cout <<"radice incorretta\n";
}

bool controlloRadice(double x,double sqrt_x)
{
	double n;
	n=sqrt(x);
	return(n==sqrt_x);
}