#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int popolatore(int popo, int perc_mo, int trasfe, int anni);

int main()
{
	float popo,perc_mo,tot,trasfe,anni;
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
	cout <<"numero anni: \n";
	cin >>anni;
	tot=popolatore(popo,perc_mo,trasfe,anni);
	if(tot>=0)	cout <<"numero di abitanti dopo un anno: " <<tot <<endl;
	else	cout <<"numero di abitanti dopo un anno 0\n";
}

int popolatore(int popo, int perc_mo, int trasfe, int anni)
{
	float tot;
	tot=popo;
	for(anni; anni>0; anni--)
	{
	tot=tot-tot*perc_mo/100.0;
	tot=tot+trasfe;
	}
	popo=tot;
	return(tot);
}