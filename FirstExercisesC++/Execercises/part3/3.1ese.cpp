#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	float s,m,b;
	b=0;
	s=0;
	int i=1;
	cout <<"inserire qualunque carattere ch non sia un numero reale  per fare la media\n";
	while (!cin.fail()){
		cout <<"inserire valore " <<i <<endl;
		cin >>b;
		s=s+b;
		i++;
	}
	m=s/(i-2);
	cout <<"la media risulta: " <<m <<endl;
}