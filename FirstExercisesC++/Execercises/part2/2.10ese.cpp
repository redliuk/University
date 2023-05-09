#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	int a;
	cout <<"inserire valore:\n";
	cin >>a;
	if ((a<=0) && (a>=-20)) {
		cout <<"Freddo dannato\n";
	}
	if ((a<=15) && (a>=1)) {
		cout <<"Freddo\n";
	}
	if ((a<=23) && (a>=16)) {
		cout <<"Normale\n";
	}
	if ((a<=30) && (a>=24)) {
		cout <<"Caldo\n";
	}
	if ((a<=40) && (a>=31)) {
		cout <<"Caldo da morire\n";
	}
	if ((a<-20) && (a>40)) {
		cout <<"Non ci credo, il termometro deve essere rotto\n";
	}
}