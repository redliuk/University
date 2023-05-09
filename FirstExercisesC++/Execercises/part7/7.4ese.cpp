#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const int a=4;

void f(int vv[a]);

int main()
{
	int v[a];
	int *p=v;
	cout <<"Dimensione di v == " <<sizeof(v) <<endl;
	cout <<"v ha dimensione " <<sizeof(v)/sizeof(v[0]) <<endl;
	cout <<"Dimensione di p == " <<sizeof(a) <<endl;
	f(v);
}

void f(int vv[a])
{
cout <<"Dimensione del parametro == " <<sizeof(a) <<endl;
}