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
	if (a<0)
	{
		a=abs(a);	
	}

		while (a>0)
		{
			c=a%10;	a=a/10;	b=b*10;	b=b+c;
		}
	b=b*-1;
	cout <<"il numero invertito risulta essere: " <<b <<endl;
}