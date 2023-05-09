#include <iostream>
#include <string>
#include <math.h>
using namespace std;

float conta (int x);

int main()
{
	int n;
	float mt;
	cout <<"di quanti numeri vuoi fare la media?" <<endl;
	cin >>n;
	mt=conta(n);
	cout << "la media dei valori inseriti risulta: " <<mt <<endl;
}

float conta (int x)
{
	float a,m;
	float s=0;
	a=0;
	for (int i=x; i>0; i--) 
	{
		cout <<"inserire un valore" <<endl;
		cin >>a;
		s=s+a;
	}
	m=s/x;
	return(m);
}