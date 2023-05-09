#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	float a,b,c,d,res1,res2;
	cout <<"inserire tre valori: \n";
	cin >>a >>b >>c;
	d=pow(b,2)-4*a*c;
	if (d<0) {
		cout <<"le radici dell'equazione corrispondente ai valori dati sono immaginarie:\n";
	}
	else {
	res1=(sqrt(d)-b)/2;
	res2=(-sqrt(d)-b)/2;
	cout <<"le radici dell'equazione corrispondente ai valori dati sono: " <<res1 <<" " <<res2;
	}
}