#include <iostream>
#include <string>
using namespace std;
int main() {
	int h,m,hm,t;
	cout <<"digitare ora compresa tra 0 e 23: " <<endl;
	cin >>h;
	hm=h*60;
	cout <<"digitare il minuto compreso tra 0 e 59: " <<endl;
	cin >>m;
	t=hm+m;
	cout <<"i minuti totali corrispondenti sono: " <<t <<endl;
}