#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	float a,c;
	cout <<"inserire anno\n";
	cin >>a;
	c=0;
	cout <<"in numeri romani:\n";
	while (a>=1000) {
		a=a-1000;
		c++;
	}
	if (a>=900) {
	cout <<"CM";
	a=a-900;
	}
	for (c; c>0; c--) {
		cout <<"M";
	}
	while (a>=500) {
		a=a-500;
		c++;
	}
	if (a>=400) {
	cout <<"CD";
	a=a-400;
	}
	for (c; c>0; c--) {
		cout <<"D";
	}
	while (a>=100) {
		a=a-100;
		c++;
	}
	if (a>=90) {
	cout <<"XD";
	a=a-90;
	}
	for (c; c>0; c--) {
		cout <<"C";
	}
	while (a>=50) {
		a=a-50;
		c++;
	}
	if (a>=40) {
	cout <<"XL";
	a=a-40;
	}
	for (c; c>0; c--) {
		cout <<"L";
	}
	while (a>=10) {
		a=a-10;
		c++;
	}
	if (a>=9) {
	cout <<"IX";
	a=a-9;
	}
	for (c; c>0; c--) {
		cout <<"X";
	}
	while (a>=5) {
	a=a-5;
	c++;
	}
	if (a>=4) {
	cout <<"IV";
	a=a-4;
	}
	for (c; c>0; c--) {
		cout <<"V";
	}
	while (a>=1) {
	a=a-1;
	c++;
	}
	if (a>=4) {
	cout <<"IV";
	a=a-9;
	}
	for (c; c>0; c--) {
		cout <<"I";
	}
	cout <<endl;
}