#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int a,b,c,k;
	b=0;
	cout <<"inserire un valore intero positivo" <<endl;
	cin >>a;
	while (a<0)
	{
		cout <<"valore dato non accettabile, inserire nuovo valore" <<endl;
		cin >>a;
	}

		while (a>0)
		{
			c=a%10;	a=a/10;	b=b*10;	b=b+c;
		}
	
	cout <<"il numero invertito risulta essere: " <<b <<endl;
}