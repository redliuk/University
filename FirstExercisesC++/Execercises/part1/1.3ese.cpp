#include <iostream>
#include <string>
using namespace std;
int main(){
	int a,b,c;
	c=0;
	cout <<"inserire due valori interi:" <<endl;
	cin >>a >>b;
	c=a;
	a=b;
	b=c;
	cout <<"i valori scambiati sono: " <<a <<" " <<b <<endl;
} 