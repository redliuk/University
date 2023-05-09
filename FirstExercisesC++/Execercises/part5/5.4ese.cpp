#include <iostream>
#include <string>
#include <math.h>
using namespace std;
struct Point
{
	double x; double y;
};

struct Rect
{
	Point pa; 
	Point pb;
};

//double Pointask(Point d);

int main()
{
	int i=0;
	Rect a; Rect b;
	cout <<"punto in alto a sinistra primo rettangolo: \n";
	cout << "inserire ascissa del punto: \n";
	cin >>a.pa.x;
	cout<< "inserire ordinata del punto: \n";
	cin >>a.pa.y;
	cout <<"punto in basso a destra primo rettangolo: \n";
	cout<< "inserire ascissa del punto: \n";
	cin >>a.pb.x;
	cout<< "inserire ordinata del punto: \n";
	cin >>a.pb.y;
	cout <<"punto in alto a sinistra secondo rettangolo: \n";
	cout << "inserire ascissa del punto: \n";
	cin >>b.pa.x;
	cout<< "inserire ordinata del punto: \n";
	cin >>b.pa.y;
	cout <<"punto in basso a destra secondo rettangolo: \n";
	cout<< "inserire ascissa del punto: \n";
	cin >>b.pb.x;
	cout<< "inserire ordinata del punto: \n";
	cin >>b.pb.y;
	if (a.pa.x<b.pa.x && a.pa.y>b.pa.y && a.pb.x>b.pb.x && a.pb.y<b.pb.y)	i=1;	
	if (a.pa.x>b.pa.x && a.pa.y<b.pa.y && a.pb.x<b.pb.x && a.pb.y>b.pb.y)	i=2;
	switch (i) 
	{ 
		case 1:
			cout <<"il primo triangolo contiene il secondo\n";
		break;
		case 2:
			cout <<"il secondo triangolo contiene il primo\n";
		break;
		default:
			cout <<"i due triangoli non sono contenuti\n";
	}
}