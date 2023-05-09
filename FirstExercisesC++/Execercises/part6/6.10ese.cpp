#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

int cifre(int a);

int main()
{
	int a;
	cout <<"inserire un valore intero positivo" <<endl;
	cin >>a;
	cout <<"il numero di cifre è: " <<reverse(a) <<endl;
}

int cifre(int a)
{
	int i;
	i=0;
	while (a>=1)
	{
		a=a/10;
		i++;
	}
	return (i);
}