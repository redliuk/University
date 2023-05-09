#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int dime,conta,conta2,ripe;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	ripe=0;
	int source[dime];
	for (conta=0; conta<dime; conta++)
	{
		cout <<"inserire il valore numero " <<conta <<endl;
		cin >>source[conta];
	}
	for (conta=0; conta<dime; conta++)
	{
		ripe=0;
		for (conta2=0; conta2<dime; conta2++)
		{
			if (source[conta]==source[conta2]) ripe++;
		}
		cout <<"il valore: " <<conta <<"si ripete " <<ripe <<" volte" <<endl;
	}
}
