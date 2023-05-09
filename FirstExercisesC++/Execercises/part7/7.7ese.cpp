#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int contaCifre(char p[], int n);

int main()
{
	int tot;
	char array[10];
	for (int i=0; i<10; i++)
	{
		cout <<"inserire il valore n." <<i <<endl;
		cin >>array[i];
	}
	tot=contaCifre(array,10);
	cout <<"il numero di cifre risulta: " <<tot <<endl;
}

int contaCifre(char p[], int n)
{
	int conta=0;
	for(int i=0; i<n; i++)
	{
		if (*(p+i)>='0' && *(p+i)<='9') conta++;
	}
	return(conta);
}