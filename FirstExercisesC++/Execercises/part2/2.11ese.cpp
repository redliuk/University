#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	int a;
	cout <<"inserire valore:\n";
	cin >>a;
	if ((a<1) || (a>12)) {
		cout <<"valore non corretto, reinserire valore intero:\n";
		cin >>a;
	}
	switch (a) {
		case 1:
			cout <<"gennaio\n";
		break;
		case 2:
			cout <<"febbraio\n";
		break;
		case 3:
			cout <<"marzo\n";
		break;
		case 4:
			cout <<"aprile\n";
		break;
		case 5:
			cout <<"maggio\n";
		break;
		case 6:
			cout <<"giugno\n";
		break;
		case 7:
			cout <<"luglio\n";
		break;
		case 8:
			cout <<"agosto\n";
		break;
		case 9:
			cout <<"settembre\n";
		break;
		case 10:
			cout <<"ottobre\n";
		break;
		case 11:
			cout <<"novembre\n";
		break;
		case 12:
			cout <<"dicembre\n";
		break;
	
	}

}