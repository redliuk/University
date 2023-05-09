#include <iostream>
#include <string>
using namespace std;
int main() {
	int a,b,c,d;
	cout <<"inserire tre interi:" <<endl;
	cin >>a >>b >>c;
	d=a;
	if (d<b) {
		a=b;
		b=d;
	}
	if (a<c) {
		d=a;
		a=c;
		c=d;
	}
	if (b<c) {
		d=b;
		b=c;
		c=d;
	}
	cout <<"i numeri inseriti in ordinine crescente risultano: "
		 <<a <<" " <<b <<" " <<c <<endl;
}