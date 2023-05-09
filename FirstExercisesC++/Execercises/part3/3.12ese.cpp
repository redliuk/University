#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int a,b,c,i,g,v;
	cout <<"inserire un valore intero: " <<endl;
	cin >>a;
	b=2*a+1;
	cout <<"guarda che bel rombo" <<endl;
	c=0; g=a; v=1;
	while (c<a) 
	{
		for (i=0; i<g; i++) 
		{
			cout <<" ";
		}
		for (i=0; i<v; i++)
		{
			if (i>0) cout <<"xx";
		}
		cout <<"x" <<endl;
		v++;
		g--;
		c++;
	}
	for (i=0; i<b; i++) cout <<"x";
	cout <<endl;
	c=0; g=a; v=1;
	while (c<a) 
	{
		for (i=0; i<v; i++) 
		{
			cout <<" ";
		}
		for (i=0; i<g; i++)
		{
			if (i>0) cout <<"xx";
		}
		cout <<"x" <<endl;
		v++;
		g--;
		c++;
	}
	cout <<endl;
}