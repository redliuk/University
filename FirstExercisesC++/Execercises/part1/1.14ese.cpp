#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	float a,b,c,d,e,f;
	cout <<"insrire due valori: " <<endl;
	cin >>a >>b;
	c=(a+b)/2;
	d=(a-b)/2;
	e=c+d;
	f=e+fabs(d)*2;
	cout <<e <<endl <<f <<endl;
}