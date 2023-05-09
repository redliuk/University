#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int i,a;
	cout <<"inserire un valore positivo: " <<endl;
	cin >>a;
	if (a==0)
	{
		cout <<"il fattoriale di 0 è 1" <<endl;
	}
	if (a<0) 
	{
		cout <<"avevo detto positivo" <<endl;
	}
	if (a>0)
	{
		for (i=a-1; i>1; i--) 
		{
			a=a*i;
		}
		cout <<"il fattoriale del valore dato è: " <<a <<endl;
	}	
}