#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

void trapezio(int bmagg, int bmin);

int main()
{
	int b,a,c;
	cout <<"inserire due valori per le basi del trapezio rettangolo, base 1: \n";
	cin >>a;
	cout <<"base 2: \n";
	cin >>b;
	trapezio(a,b);
}

void trapezio(int bmagg, int bmin)
{
	float c,scambio;
	c=abs(bmagg-bmin)+1;
	if (bmagg<bmin) 
	{
		scambio=bmin;	bmin=bmagg;	bmagg=scambio;
	}
	while (c>0) 
	{
		for (int i=0; i<bmin; i++) 
		{
			cout <<"x";
		}
		cout <<endl;
		bmin++;	c--;
	}
}