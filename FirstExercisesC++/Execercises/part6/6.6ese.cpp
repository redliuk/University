#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

int factorial (int x);

int main()
{
	int num;
	cout <<"inserire valore\n";
	cin >>num;
	try{
	cout <<factorial(num) <<" è il fattoriale di " <<num <<endl;
	}
	catch (string& err) {cout <<err;}
	catch (string& err1) {cout <<err1;}
}

int factorial (int a)
{
		int i;
		string err,err1;
		err="valori negativi non accettabili\n";
		err1="il fattoriale di 0 è 1\n";
	if (a<0) throw err;
	if (a==0) throw err1;
	if (a>0)
	{
		for (i=a-1; i>1; i--) 
		{
			a=a*i;
		}
	}	
	return(a);
}