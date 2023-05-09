#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	int a,b,c,d;
cout <<"inserire tre interi:" <<endl;
	cin >>a >>b >>c;
	d=a;
	if (b<d) {
		a=b;
		b=d;
	}
	if (c<a) {
		d=a;
		a=c;
		c=d;
	}
	if (c<b) {
		d=b;
		b=c;
		c=d;
	}
	cout <<"i numeri inseriti in ordinine crescente risultano: "
		 <<a <<" " <<b <<" " <<c <<endl;
}