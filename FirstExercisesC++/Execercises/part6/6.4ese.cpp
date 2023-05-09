#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

float media (float base, float altezza);

int main()
{
	float a,b,m;
	cout << "inserire valore altezza: \n";
	cin >>a;
	cout << "inserire valore base: \n";
	cin >>b;
	try
	{
	m=media(a,b);
	cout <<"la media risulta "<<media(a,b) <<endl;
	}
	catch (string& err1) {cout <<err1;}
	catch (string& err2) {cout <<err2;}
}

float media (float base, float altezza)
{
	string err1,err2;
	float a; a=base*altezza; 
	err1="un valore dato non è positivo\n";
	err2="un valore dato è nullo\n";
	if (base<0 || altezza<0) throw err1;
	if (base==0 || altezza==0) throw err2;
	return(a);
}