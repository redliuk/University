#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int i,a,f;
	f=1;
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
		for (i=a-1; i>=1; i--) 
		{
			f=f*(a-i);
		}
		f=f*a;
		cout <<"il fattoriale del valore dato è: " <<f <<endl;
	}	
}