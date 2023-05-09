#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int a,b,c,d,i;
	cout <<"inserire un valore intero\n";
	cin >>a;
	b=a; d=0;
	for (i=0; b>0; i++)
	{
		c=b%10;
		d=d*10;
		b=b/10;
		d=d+c;
	}
	cout <<"il valore dato ";
	if (a!=d) cout <<"non ";
	cout <<"è palindromo" <<endl;
}