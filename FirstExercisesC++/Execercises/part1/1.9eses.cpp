#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
	double a,b,c,pt,pt2,A;
	cout <<"inserire valore lato1: " <<endl;
	cin >>a;
	cout <<"inserire valore lato2: " <<endl;
	cin >>b;
	cout <<"inserire valore lato3: " <<endl;
	cin >>c;
    pt=a+b+c;
    pt2=pt/2;
    A=sqrt(pt2*(pt2-a)*(pt2-b)*(pt2-c));
    cout <<"l'area del triangolo è: " <<A <<endl
    	 <<"il perimetro del triangolo è: " <<pt <<endl;
}