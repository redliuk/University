#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	int a;
	if (a<0) {
		a=a*-1;
	}
	cout <<"inserire un valore intero:" <<endl;
	cin >>a;
	fabs(a);
	cout <<"valore assoluto di a: "
		 <<abs(a) <<endl;
}