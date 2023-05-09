#include <iostream>
#include <string>
#include <math.h>
using namespace std;
struct Point
{
	double x;
	double y;
};
int main()
{
	Point a,b;
	float t,da,db,distanza;
	t=0.1;
	cout <<"inserire valore ascissa primo punto: \n";
	cin >>a.x;
	cout <<"inserire valore ordinata primo punto: \n";
	cin >>a.y;
	da=abs(a.y-a.x);
	if (da<t)
		{
			cout <<"primo punto troppo prossimo all'origine\n";	
			return(0);
		} 
	cout <<a.x <<" " <<a.y <<endl;
	cout <<"inserire valore ascissa secondo punto: \n";
	cin >>b.x;
	cout <<"inserire valore ordinata secondo punto: \n";
	cin >>b.y;
	cout <<b.x <<" " <<b.y <<endl;
	db=abs(b.y-b.x);
	if (db<t)
		{
			cout <<"secondo punto troppo prossimo all'origine\n";	
			return(0);
		}
	if ((a.x-b.x)==0 && (a.y-b.y)==0) 		
	{
		cout <<"i punti coincidono!\n";
	}
	else
	{
	cout <<"il secondo punto é";
	if (a.y<b.y)
		{
			cout <<" in alto";
		}
	if (a.y>b.y)
		{
			cout <<" in basso";
		}	
	if (a.x<b.x)
		{
			cout <<" a destra";
		}	
	if (a.x>b.y)
		{
			cout <<" a sinistra";
		}
	}
	cout <<" rispetto al primo\n";
	distanza=sqrt(fabs(a.x-b.x)+fabs(a.y-b.y));
	cout <<"la distanza dei due punti è: " <<distanza <<endl;
}