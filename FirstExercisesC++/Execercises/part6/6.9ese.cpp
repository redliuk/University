#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

int reverse(int a);

int main()
{
	int z,rev;
	cout <<"Inserire un numero intero positivo: ";
	cin >>z;
	try 
	{
		rev=reverse(z);
		cout <<"Rovesciando " <<z <<" si ottiene " <<rev <<endl;
	}
	catch (string& err)	{cout <<err;}
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