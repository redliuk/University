#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

int cifradieci(int n, int d);

int main()
{
	int num,cifra;
	cout <<"inserire cifra tra 0 e 9: \n";
	cin >>cifra;
	cout <<"inserire numero massimo maggiore: \n";
	cin >>num;
	while (cifra<0 || cifra>9 || num<=10)
	{
		cout <<"un valore inserito non è valido, riprovare\n";
		cout <<"inserire cifra tra 0 e 9: \n";
		cin >>cifra;
		cout <<"inserire numero massimo: \n";
		cin >>num;
	}
	cout <<"il valore massimo risulta: " <<cifradieci(num, cifra) <<endl;
}

int cifradieci(int n, int d)
{
	int t,i;
		i=0;
	while (n>0)
	{
		t=n/pow(10,i);
		for (int i=0; t>0; i++)
		{
			t=n/pow(10,i);
			if (t%10==d) return(n);
		}
	n--;
	}
}