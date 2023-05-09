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

double StraightLine(Line c, Point d)
{
	double y,x,tolle;
	cout<< "inserire coefficente angolare retta: \n";
 	cin >>c.coeff;
	cout<< "inserire quota retta: \n";
	cin >>c.quota;
	cout <<"l'eq. della retta risulta: y=" <<c.coeff <<"x + " <<c.quota <<endl;
	cout<< "inserire ascissa di un punto: \n";
	cin >>d.x;
	cout<< "inserire ordinata del punto: \n";
	cin >>d.y;
	tolle=0.1;
	if(tolle>abs(d.x-d.y)) {cout <<"tolleranza superata\n"; return(0);}
	if (c.coeff*d.x-d.y+c.quota<tolle) cout <<"il punto appartiene alla retta\n";
	else cout <<"il punto non appartiene alla retta\n";
}

int main()
{
	Line retta;
	Point punto;
	StraightLine(retta, punto);
}