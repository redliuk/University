#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

float media();

int main()
{
	float m;
	m=media();
	cout <<"la media è: " <<m <<endl;
}

float media()
{
	string a;
	float b,i,somma,media;
	somma=0; i=0;
	while (a!="no")
	{
		cout <<"inserire un valore" <<endl;
		cin >>b;
		cout <<"il valore dato è: " <<b <<endl;
		cout <<"continuare con l'inserimento?" <<endl;
		cin >>a;
		somma=somma+b;
		i++;
	}
	media=somma/i;
	return (media);
}