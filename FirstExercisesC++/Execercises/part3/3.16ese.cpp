#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int a,c,i,p;
	i=2; 
	cout <<"inserire un valore positivo\n";
	cin >>a;
	cout <<"il numero scomposto in fattori primi è: 1";
	while (a>1)
	{
		for (c=1; c<=i; c++)
		{
			if (i%c==0 && i==c)
			{
				p=0;
				while (a%i==0)
				{
					for (p=0; a%i==0; p++) a=a/i;
					cout <<"*" <<i <<"^" <<p;
				}	
			}
		}
		i++;
	}
	cout <<endl;
}