#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	int a;
	cout <<"inserire un anno: \n";
	cin >>a;
	if(((a%100==0) && (a%400==0)) || ((a%100!=0) && (a%4==0))) {
			cout <<"l'anno digitato è bisestile\n";
		}
	else {cout <<"l'anno digitato è non bisestile\n";}
}