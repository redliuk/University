#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int a,i,f;
	cout <<"inserire un valore positivo: " <<endl;
	cin >>a;
	for (f=0; f<a; f++)
	{	
		for (i=0; i<=f; i++) 
		{
			cout <<'*';
		}
		cout <<endl;
	}	
}