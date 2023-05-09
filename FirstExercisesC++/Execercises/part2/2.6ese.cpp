#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	float a,b,c;
	cout <<"insere tre valori: " <<endl;
	cin >>a >>b >>c;
	if (a>(b+c) || b>(c+a) || c>(a+b)){
		cout <<"non sono i lati di un triangolo\n";
	}
	if (a<fabs(c-b) || b<fabs(a-c) || c<fabs(a-b)){
		cout <<"non sono i lati di un triangolo\n";
	}
	else {
		cout <<"sono i lati di un triangolo\n"; 
	}
}