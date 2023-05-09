#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	double a,b;
	cout <<"inserire un numero reale\n";
	cin >>a;
	b=a;
	b=b/4.9;
	b=b/3.53;
	b=b/6.9998;
	b=b*4.9;
	b=b*3.53;
	b=b*6.9998;
	
	if (a!=b) {
		cout  <<"i numeri son diversi\n" <<b <<endl;
	}
cout <<b <<endl;
}