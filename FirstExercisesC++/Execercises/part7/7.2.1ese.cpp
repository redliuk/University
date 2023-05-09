#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct array_str
{
	int array[10];
};

void reverseWrong(array_str &source,array_str &dest);

int main()
{
	array_str source,dest;
	for (int conta=0; conta<10; conta++)
	{
		cout <<"inserire il valore intero numero " <<conta <<endl;
		cin >>source.array[conta];
	}
	try
	{
	reverseWrong(source,source);	
	for (int conta=0; conta<10; conta++)
	{
		cout <<source.array[conta] <<" ";
	}
	}
	catch (string err) {cout <<err;}
	cout <<endl;
}

void reverseWrong(array_str &source,array_str &dest)
{	
	int i,scamb;
	array_str *p=&dest;
	array_str *p1=&source;
	string err="non è possibile lo stesso parametro attuale per i parametri formali della funzione\n";
	if (p1==p) throw err;
	for (int i=0; i<5; ++i) 
	{
		source.array[i]=source.array[10-1-i];
	}
}