#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

void replicate_2line(int f, int s, char f_c, char s_c);
void rombo(int f);

int main()
{
	int a;
	cout <<"inserire un valore intero: " <<endl;
	cin >>a;
	cout <<"guarda che bel rombo" <<endl;
	rombo(a);
}

void replicate_2line(int f, int s, char f_c, char s_c)
{
	for (f; f>0; f--)
	{
		cout <<f_c;
	}
	for (s; s>0; s--)
	{
		cout <<s_c;
	}
	cout <<endl;
}

void rombo(int f)
{
	int b,c,i,g;
	char s_c,f_c;
	f_c=' '; s_c='x';
	b=2*f+1;
	g=f; i=1; c=0;
	while (c<f) 
		{
			replicate_2line(g,i,f_c, s_c);
			i=i+2;	g--;	c++;
		}
	for (i=0; i<b; i++) cout <<"x";
	cout <<endl;
	c=0; g=1; i=b-2;
	while (c<f) 
		{
			replicate_2line(g,i,f_c, s_c);
			i=i-2;	g++;	c++;
		}
	cout <<endl;
}