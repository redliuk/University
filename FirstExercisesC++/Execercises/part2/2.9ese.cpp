#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	char x,y;
	cout <<"scelta al primo giocatore" <<endl <<"digitare c per carta" <<endl <<"digitare f per forbice" <<endl <<"digitare s per sasso\n";
	cin >>x;
	cout <<"scelta al secondo giocatore" <<endl <<"digitare c per carta" <<endl <<"digitare f per forbice" <<endl <<"digitare s per sasso\n";
	cin >>y;
	if (x==y) {
		cout <<"pareggio\n";
	}
	switch (x) {
		case 'c':
			switch (y) {
				case 's':
					cout <<"vince il primo giocatore\n";
				break;
				default:
					cout <<"vince il secondo giocatroe\n";
			}
		break;
		case 'f':
			switch (y) {
				case 'c':
					cout <<"vince il primo giocatore\n";
				break;
				default:
					cout <<"vince il secondo giocatroe\n";
			}
		break;
		case 's':
			switch (y) {
				case 'f':
					cout <<"vince il primo giocatore\n";
				break;
				default:
					cout <<"vince il secondo giocatroe\n";
			}
		break;
	}
}