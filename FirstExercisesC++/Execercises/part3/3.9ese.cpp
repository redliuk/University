#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int a,i;
	i=0;
	cout <<"inserire un valore intero positivo" <<endl;
	cin >>a;
	while (a>=1)
	{
		a=a/10;
		i++;
	}
	cout <<"il numero di cifre è: " <<i <<endl;
}