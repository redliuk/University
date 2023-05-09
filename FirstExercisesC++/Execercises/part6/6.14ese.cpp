#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

void replicate_2line(int f, int s, char f_c, char s_c);

int main()
{
	int n1,n2;
	char c1,c2;
	cout <<"inserire due valori numerici interi: \n";
	cin >>n1 >>n2;
	cout <<"inserire due caratteri: \n";
	cin >>c1 >>c2;
	replicate_2line(n1,n2,c1,c2);
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