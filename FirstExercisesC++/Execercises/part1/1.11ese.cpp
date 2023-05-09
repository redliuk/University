#include <iostream>
#include <string>
#include <math.h>
#define PI 3.1419
using namespace std;
int main() {
	float r,c,a;
	cout <<"inserire valore raggio: " <<endl;
	cin >>r;
	c=2*r*PI;
	cout <<"il valore della circonferenza è: " <<c <<endl;
	a=pow(r,2)*PI;
	cout <<"il valore dell'area è: " <<a <<endl;
}