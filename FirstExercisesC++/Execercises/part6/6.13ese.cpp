#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool moltdiv (float x,float y,float z);

int main()
{
	float a,b,c;
	cout <<"inserire 3 valori reali: \n";
	cin >>a >>b >>c;
	if (moltdiv(a,b,c)) cout <<"il risultato è 1" <<endl;
	else cout <<"il risultato non è 1" <<endl;
}

bool moltdiv (float x,float y,float z)
{
	float d,d1,d2,d3;
	bool v=false;
	d=x*y*z;
	d1=d/x; d2=d1/y; d3=d2/z;
	if (d3==1) v=true;
	return(v);	
}