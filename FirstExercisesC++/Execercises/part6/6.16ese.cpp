#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

bool palindromo(int n);
int reverse(int a);

int main()
{
	int a;
	cout <<"inserire un valore intero: " <<endl;
	cin >>a;
	if (palindromo(a)) cout <<"il numero dato è palindromo\n";
	else cout <<"il numero dato è non palindromo\n";
}

bool palindromo(int n)
{
	int girato;
	girato=reverse(n);
	return(girato==n);
}

int reverse(int a)
{
	int b,c,k;
	b=0;
	string err="valore dato non accettabile siccome negativo\n";
	if (a<0) throw err;
	while (a>0)
	{
		c=a%10;	a=a/10;	b=b*10;	b=b+c;
	}
	return(b);
}