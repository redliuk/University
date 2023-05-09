#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

int tria (int x);

int main()
{
	int a;
	cout <<"inserire un valore positivo: " <<endl;
	cin >>a;
	try 
	{
		tria(a);
	}
	catch (string& err) {cout <<err;}
}

int tria (int a)
{
	int i,f;
	string err="valore non positivo\n";
	if (a<0) throw err;
	for (f=0; f<a; f++)
	{	
		for (i=0; i<=f; i++) 
		{
			cout <<'*';
		}
		cout <<endl;
	}
}