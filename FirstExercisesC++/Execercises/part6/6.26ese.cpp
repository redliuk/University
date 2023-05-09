#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int mezzoPopolatore(int popo, int perc_mo);

int main()
{
	float popo,perc_mo,tot;
	int perc;
	cout <<"numero abitanti: \n";
	cin >>popo;
	while (popo<0)
	{
	cout <<"errore numero abitanti negativo, ripetere inserimento: \n";
	cin >>popo;
	}
	cout <<"percentuale di morti al netto delle nascite: \n";
	cin >>perc_mo;
	while (perc_mo<-100 && perc_mo>100)
	{
	cout <<"errore valore percentuale invalido, ripetere inserimento: \n";
	cin >>perc_mo;
	}
	tot=mezzoPopolatore(popo,perc_mo);
	if(perc_mo>=0)	cout <<"numero di anni per il raddoppiamento: " <<tot <<endl;
	else	cout <<"numero di anni per il dimezzamento: " <<tot <<endl;
}

int mezzoPopolatore(int popo, int perc_mo)
{
	float tot,mezzo,doppio,anni;
	doppio=popo*2;
	tot=popo;
	perc_mo=abs(perc_mo);
	while(tot<=doppio)
	{
	tot=tot+tot*perc_mo/100.0;
	anni++;
	}
	return(anni);
}