#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int a;
	do
	{
	cout <<"1 per prima scelta" <<endl;
	cout <<"2 per seconda scelta" <<endl;
	cout <<"3 per terza scelta" <<endl;
	cout <<"0 per uscire dal programma" <<endl;
	cin >>a;
	if (a<0 || a>3) cout <<"scelta non valida, ripetere la scelta" <<endl;
	if (a==1) cout <<"avete selezionato la prima scelta" <<endl;
	if (a==2) cout <<"avete selezionato la seconda scelta" <<endl;
	if (a==3) cout <<"avete selezionato la terza scelta" <<endl;
	if (a==0) {cout <<"Hai scelto di uscire dal programma" <<endl; return(0);}
	}
	while (a!=0);
}
