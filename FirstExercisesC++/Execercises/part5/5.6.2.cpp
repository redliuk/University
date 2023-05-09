#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Point
{
	int x; int y;
};

struct Triangle
{
	Point v1; Point v2; Point v3;
	double area; double perimetro;
};

int main()
{
	double l1,l2,l3,p;
	double componente1,componente2,componente3,scambio;
	Triangle tria,tria1,tria2;
		cout <<"PRIMO TRIANGOLO \n";
		cout <<"inserire valori primo vertice: \n";
		cout <<"inserire coordinate ascissa: \n";
		cin >>tria.v1.x;
		cout <<"inserire coordinate ordinata: \n";
		cin >>tria.v1.y;
		cout <<"inserire valori secondo vertice: \n";
		cout <<"inserire coordinate ascissa: \n";
		cin >>tria.v2.x;
		cout <<"inserire coordinate ordinata: \n";
		cin >>tria.v2.y;
		cout <<"inserire valori terzo vertice: \n";
		cout <<"inserire coordinate ascissa: \n";
		cin >>tria.v3.x;
		cout <<"inserire coordinate ordinata: \n";
		cin >>tria.v3.y;
		componente1=pow((tria.v1.x-tria.v2.x),2)+pow((tria.v1.y-tria.v2.y),2);
		componente2=pow((tria.v2.x-tria.v3.x),2)+pow((tria.v2.y-tria.v3.y),2);
		componente3=pow((tria.v3.x-tria.v1.x),2)+pow((tria.v3.y-tria.v1.y),2);
		l1=sqrt(componente1);
		l2=sqrt(componente2);
		l3=sqrt(componente3);
		tria.perimetro=l1+l2+l3;
		p=tria.perimetro/2;
		tria.area=sqrt(p*(p-l1)*(p-l2)*(p-l3));
		cout <<"SECONDO TRIANGOLO \n";
		cout <<"inserire valori primo vertice: \n";
		cout <<"inserire coordinate ascissa: \n";
		cin >>tria1.v1.x;
		cout <<"inserire coordinate ordinata: \n";
		cin >>tria1.v1.y;
		cout <<"inserire valori secondo vertice: \n";
		cout <<"inserire coordinate ascissa: \n";
		cin >>tria1.v2.x;
		cout <<"inserire coordinate ordinata: \n";
		cin >>tria1.v2.y;
		cout <<"inserire valori terzo vertice: \n";
		cout <<"inserire coordinate ascissa: \n";
		cin >>tria1.v3.x;
		cout <<"inserire coordinate ordinata: \n";
		cin >>tria1.v3.y;
		componente1=pow((tria1.v1.x-tria1.v2.x),2)+pow((tria1.v1.y-tria1.v2.y),2);
		componente2=pow((tria1.v2.x-tria1.v3.x),2)+pow((tria1.v2.y-tria1.v3.y),2);
		componente3=pow((tria1.v3.x-tria1.v1.x),2)+pow((tria1.v3.y-tria1.v1.y),2);
		l1=sqrt(componente1);
		l2=sqrt(componente2);
		l3=sqrt(componente3);
		tria1.perimetro=l1+l2+l3;
		p=tria1.perimetro/2;
		tria1.area=sqrt(p*(p-l1)*(p-l2)*(p-l3));
		cout <<"TERZO TRIANGOLO \n";
		cout <<"inserire valori primo vertice: \n";
		cout <<"inserire coordinate ascissa: \n";
		cin >>tria2.v1.x;
		cout <<"inserire coordinate ordinata: \n";
		cin >>tria2.v1.y;
		cout <<"inserire valori secondo vertice: \n";
		cout <<"inserire coordinate ascissa: \n";
		cin >>tria2.v2.x;
		cout <<"inserire coordinate ordinata: \n";
		cin >>tria2.v2.y;
		cout <<"inserire valori terzo vertice: \n";
		cout <<"inserire coordinate ascissa: \n";
		cin >>tria2.v3.x;
		cout <<"inserire coordinate ordinata: \n";
		cin >>tria2.v3.y;
		componente1=pow((tria2.v1.x-tria2.v2.x),2)+pow((tria2.v1.y-tria2.v2.y),2);
		componente2=pow((tria2.v2.x-tria2.v3.x),2)+pow((tria2.v2.y-tria2.v3.y),2);
		componente3=pow((tria2.v3.x-tria2.v1.x),2)+pow((tria2.v3.y-tria2.v1.y),2);
		l1=sqrt(componente1);
		l2=sqrt(componente2);
		l3=sqrt(componente3);
		tria2.perimetro=l1+l2+l3;
		p=tria2.perimetro/2;
		tria2.area=sqrt(p*(p-l1)*(p-l2)*(p-l3));
		if (tria.area>tria1.area && tria.area>tria2.area) 
			cout <<"il primo triangolo ha area maggiore\n";
		if (tria1.area>tria.area && tria1.area>tria2.area) 
			cout <<"il secondo triangolo ha area maggiore\n";
		if (tria2.area>tria1.area && tria2.area>tria.area) 
			cout <<"il terzo triangolo ha area maggiore\n";
}