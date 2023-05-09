#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	int n=7;
	int conta;
	int *v;
	v=new int[n];
	for (conta=1; conta<=n; conta++)
	{
		v[conta]=conta*2-1;
	}
	for (conta=0; conta<n; conta++)
	{
		cout <<*(v+conta) <<" ";
	}
	cout <<endl;
	delete v;
	v=new int[2*n];
	for (conta=1; conta<=2*n; conta++)
	{
		v[conta]=conta*4-1;
	}
		for (conta=0; conta<n*2; conta++)
	{
		cout <<*(v+conta) <<" ";
	}
	cout <<endl;
}