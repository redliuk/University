#include <iostream>
#include <string>
#include <math.h>
using namespace std;
struct Point
{
	double x;
	double y;
};

struct Line
{
	double coeff;
	double quota;
};

int main()
{
	double y,x,tolle;
	Line retta;
	Point punto;
	cout<< "inserire coefficente angolare retta: \n";
	cin >>retta.coeff;
	cout<< "inserire quota retta: \n";
	cin >>retta.quota;
	cout<< "inserire ascissa di un punto: \n";
	cin >>punto.x;
	cout<< "inserire ordinata del punto: \n";
	cin >>punto.y;
	tolle=0.1;
	if(tolle<fabs(punto.x-punto.y)) {cout <<"tolleranza superata\n"; return(0);}
	cout <<"l'eq. della retta risulta: y=" <<retta.coeff <<"x + " <<retta.quota <<endl;
	if (retta.coeff*punto.x-punto.y+retta.quota<tolle) cout <<"il punto appartiene alla retta\n";
	else cout <<"il punto non appartiene alla retta\n";
}