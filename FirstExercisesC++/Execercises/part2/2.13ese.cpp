#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	int a,b;
	cout <<"inserire le ore:\n";
	cin >>a;
	cout <<"inserire i minuti:\n";
	cin >>b;
	if (((a<0) && (a>12)) || ((b<0) && (b>59))) {
		cout <<"valori dati non corretti\n";
		return -1;
	}
	switch (a) {
		case 1:
			cout <<"è l'una";
		break;	
		case 2:
			cout <<"sono le due";
		break;
		case 3:
			cout <<"sono le tre";
		break;
		case 4:
			cout <<"sono le quattro";
		break;
		case 5:
			cout <<"sono le cinque";
		break;
		case 6:
			cout <<"sono le sei";
		break;
		case 7:
			cout <<"sono le sette";
		break;
		case 8:
			cout <<"sono le otto";
		break;
		case 9:
			cout <<"sono le nove";
		break;
		case 10:
			cout <<"sono le dieci";
		break;
		case 11:
			cout <<"sono le undici";
		break;
		case 12:
			cout <<"sono le dodici";
		break;
	}
	if ((b>=15) && (b<=30)) {
		cout <<" e un quarto";
	}
	if ((b>30) && (b<45)) {
		cout <<" e mezza";
	}
	if ((b>=45) && (b<=59)) {
		cout <<" e un quarto";
	}
	if (b%15!=0) {
		cout <<" circa";
	}
			cout <<endl;
}