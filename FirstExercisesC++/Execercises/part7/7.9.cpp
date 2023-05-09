#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int i,i2;

bool isUpper(char mat[3][3]);

int main()
{
	int colonne,righe;
	char a;
	i=0;	i2=0;
	char matrice[3][3];
	for (i; i<3; i++)
	{
		cout <<"inserire valori riga n" <<i <<endl;
		for (i2=0; i2<3; i2++)
		{
			cin >>a;
			matrice[i2][i]=a;
		}
	}
	cout <<"ecco la matrice:\n" <<endl;
		for (i=0; i<3; i++)
	{
		cout <<"   ";
		for (i2=0; i2<3; i2++)
		{
			cout <<matrice[i2][i] <<" ";
		}
		cout <<endl;
	}
	cout <<endl;
	if (isUpper(matrice)) cout <<"la matrice contiene solo maiuscole\n";
	else cout <<"la matrice non contiene solo maiuscole\n";
}

bool isUpper(char mat[3][3])
{
	bool upper=true;
	char *p;
	p=mat[0];
	for (i=0;i<9; i++)
	{	
		if (*(p+i)>'Z' || *(p+i)<'A')	upper=false;
	}
	return upper;
}