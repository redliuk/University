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
	Triangle tria;
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
	cout <<"i lati del triangolo risultano:" <<l1 <<" " <<l2 <<" " <<l3 <<endl;
	cout <<"il perimetro risulta: " <<tria.perimetro <<endl;
	cout <<"l'area risulta: " <<tria.area <<endl;
	if (componente1<componente2) {scambio=componente1; componente1=componente2; componente2=scambio;}
	if (componente1<componente3) {scambio=componente1; componente1=componente3; componente3=scambio;}
	if (componente1==componente2+componente3) cout <<"il triangolo è rettangolo!\n";
	else cout <<"il triangolo non è rettangolo\n";
}