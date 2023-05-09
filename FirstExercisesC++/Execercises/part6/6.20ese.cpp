#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

int zeroFattoriale(int a);

int main()
{
	int x,zero;
	cout <<"inserire un valore intero positivo\n";
	cin >>x;
	zero=zeroFattoriale(x);
	cout <<"il fattoriale del numero dato ha " <<zero <<" zeri finali\n";
}

int zeroFattoriale(int a)
{
	int five,twfive,n;
	five=a/5;
	twfive=a/25;
	n=five+twfive;
	return(n);
}