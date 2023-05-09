#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int popolatore(int popo, int perc_mo, int trasfe);

int main()
{
	float popo,perc_mo,tot,trasfe;
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
	cout <<"persone trasferite nella città al netto di quelle che l’abbandonano: \n";
	cin >>trasfe;
	tot=popolatore(popo,perc_mo,trasfe);
	if(tot>=0)	cout <<"numero di abitanti dopo un anno: " <<tot <<endl;
	else	cout <<"numero di abitanti dopo un anno 0\n";
}

int popolatore(int popo, int perc_mo, int trasfe)
{
	popo=popo-popo*perc_mo/100.0;
	popo=popo+trasfe;
	return(popo);
}