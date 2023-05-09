#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int i=0;

void es4_6(int array[], int dime);
void es4_7(int array[], int dime);
void es4_12(int array[], int dime);
void es4_15(int array[], int dime);
void es4_17(int array[], int dime);

int main()
{
	int dime;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	int array[dime];
	int *p=array;
	for (i=0; i<dime; i++)
	{
		cout <<"inserire il valore numero " <<i <<endl;
		cin >>*(p+i); 
	}
	es4_6(array,dime);
	es4_7(array,dime);
	es4_12(array,dime);
	es4_15(array,dime);
	es4_17(array,dime);
}

void es4_6(int array[], int dime)
{
	int ripe,max;
	max=*array; ripe=0;
	for (i=0; i<dime; i++) 
	{
		if (*(array+i)>max)	max=*(array+i);
	}
	for (i=0; i<dime; i++)
	{
		if (*(array+i)==max)	ripe++;
	}
	cout <<"il valore maggiore dell'array è: " <<max <<endl;
	cout <<"il valore più alto ha " <<ripe <<" occorenze\n";
}

void es4_7(int array[], int dime)
{
	int pari,dispari;
	pari=0; dispari=0;
	for (i=0; i<dime; i++)
	{
		if (*(array+i)%2==0) pari++;
	}
	dispari=dime-pari;
	cout <<"i numeri pari sono: " <<pari <<endl;
	cout <<"i numeri dispari sono: " <<dispari <<endl;
}

void es4_12(int array[], int dime)
{
	int max;
	max=array[0];
	for (i=0; i<dime; i++) 
	{
		if (*(array+i)>max)	max=*(array+i);
	}
	max=max-1;
	cout <<"il secondo valore più elevato è: " <<max <<endl;
}

void es4_15(int array[], int dime)
{
	int copia,i;
	float scamb;
	copia=dime/2;
	for (i=0; i<copia; i++)
	{
		scamb=*(array+i);
		*(array+i)=*(array+(dime-1-i));
		*(array+(dime-1-i))=scamb;
	}
	for (i=0; i<dime; i++)
	{
		cout <<*(array+i) <<" ";
	}
	cout <<endl;
}

void es4_17(int array[], int dime)
{
	int l,conta;
	conta=0;
	for (i=0; i<dime-conta-1; i++)
	{
		while (*(array+i)==*(array+(i+1)))
		{
			l=i;			
			while (l<dime-conta)
			{
				*(array+l)=*(array+(l+1));
				l++;
				*(array+(dime-1))=0;
			}
		conta++;
		}
	}
	cout <<"i valori dell'array ora sono: " <<endl;
	for (i=0; i<dime; i++)
	{
		if(*(array+i)!=0) cout <<*(array+i) <<" ";
	}
	cout <<endl;
}