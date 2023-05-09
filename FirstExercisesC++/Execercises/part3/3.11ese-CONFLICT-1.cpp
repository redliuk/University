#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int b,a,c;
	cout <<"inserire due valori per le basi del trapezio rettangolo, base 1: " <<endl;
	cin >>a;
	cout <<"base 2: ";
	cin >>b;
	c=abs(a-b)+1;
	while (c>0) 
	{
		for (int i=0; i<a; i++) 
		{
			cout <<"x";
		}
		cout <<endl;
		a++;
		c--;
	}
}