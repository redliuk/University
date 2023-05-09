#include <iostream>
#include <string>
using namespace std;
int main() {
	bool x;
	x=3>1;
	cout << boolalpha <<"tre è maggiore di uno = " <<x <<endl;
	x=4/2<0;
	cout <<"quattro diviso due è minore di zero = " <<x <<endl;
	x="zero"==0;
	cout <<"il carattere \"zero\" è uguale al valore zero = " <<x <<endl;
	x=0<10/2<=10;
	cout <<"dieci mezzi è compreso fra zero escluso e dieci incluso = " <<x <<endl;
	x!=3>2 && 3<1;
	cout <<"non è vero che tre è maggiore di due e minore di uno = " <<x <<endl;
	x!=3<-5 || 7>0;
	cout <<"tre minore di meno cinque implica sette maggiore di zero = " <<x <<endl;
}