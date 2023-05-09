#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct array_str
{
	int array[10];
};

void reverse(array_str &source,array_str &dest);

int main()
{
	array_str source,dest;
	for (int conta=0; conta<10; conta++)
	{
		cout <<"inserire il valore intero numero " <<conta <<endl;
		cin >>source.array[conta];
	}
	reverse(source,source);
	for (int conta=0; conta<10; conta++)
	{
		cout <<source.array[conta] <<" ";
	}
	cout <<endl;
}

void reverse(array_str &source,array_str &dest)
{	
	int i,scamb;
	for (int i=0; i<5; ++i) 
	{
		scamb=source.array[i];
		source.array[i]=source.array[10-1-i];
		source.array[10-1-i]=scamb;
	}
}