#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

void contaLett(int& a, int n, int c);
void numeroRomano(int& a);

int main()
{
	int anno;
	cout <<"inserire anno tra 1 e 3000\n";
	cin >>anno;
	numeroRomano(anno);
}

void contaLett(int& a, int n, int c)
{
	char CloseRomanLetters[12]={'C','M','C','D','X','C','X','L','I','X','I','V'};
	int i=0;
	while (a>=n) 
	{
	a=a-n;
	i++;
	}
	for (i; i>0; i--) 
	{
		cout <<CloseRomanLetters[c];
	}
	if (c<=3 && a>n-100) 
	{
	cout <<CloseRomanLetters[c-1] <<CloseRomanLetters[c];
	a=a-(n-100);
	}
	if (c>3 && c<=7 && a>=n-10) 
	{
	cout <<CloseRomanLetters[c-1] <<CloseRomanLetters[c];
	a=a-(n-10);
	}
	if (c>7 && a>=n-1)
	{
	cout <<CloseRomanLetters[c-1] <<CloseRomanLetters[c];
	a=a-(n-1);
	}
}

void numeroRomano(int& a)
{
	int conta;
	cout <<"in numeri romani:\n";
	contaLett(a,1000,1);
	contaLett(a,500,3);
	contaLett(a,100,5);
	contaLett(a,50,7);
	contaLett(a,10,9);
	contaLett(a,5,11);
	while (a>=1) {
	a=a-1;
	conta++;
	}
	for (conta; conta>0; conta--) {
		cout <<"I";
	}
	cout <<endl;
}