#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int bmin,bmagg,c;
	cout <<"inserire due valori interi per le basi del trapezio rettangolo, base 1: " <<endl;
	cin >>bmin;
	cout <<"base 2: ";
	cin >>bmagg;
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