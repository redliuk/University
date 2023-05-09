#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct Time
{
	unsigned int ora;
	unsigned int minuti;
	unsigned int secondi;
};

int main()
{
	Time T1,T2;
	int diffe1,diffe2,diffe3;
	cout <<"primo tempo \n";
	cout <<"inserire ora: \n";
	cin >>T1.ora;
	while (T1.ora<0 || T1.ora>24) 
	{
		cout <<"valore ora invalido, riprovare please:\n";
		cin >>T1.ora;
	}
	cout <<"inserire minuti: \n";
	cin >>T1.minuti;
	while (T1.minuti<0 || T1.minuti>59) 
	{
		cout <<"valore ora invalido, riprovare please:\n";
		cin >>T1.minuti;
	}
	cout <<"inserire secondi: \n";
	cin >>T1.secondi;
	while (T1.secondi<0 || T1.secondi>59) 
	{
		cout <<"valore ora invalido, riprovare please:\n";
		cin >>T1.secondi;
	}
		cout <<"primo tempo \n";
	cout <<"inserire ora: \n";
	cin >>T2.ora;
	while (T2.ora<0 || T2.ora>24) 
	{
		cout <<"valore ora invalido, riprovare please:\n";
		cin >>T2.ora;
	}
	cout <<"inserire minuti: \n";
	cin >>T2.minuti;
	while (T2.minuti<0 || T2.minuti>59) 
	{
		cout <<"valore ora invalido, riprovare please:\n";
		cin >>T2.minuti;
	}
	cout <<"inserire secondi: \n";
	cin >>T2.secondi;
	while (T2.secondi<0 || T2.secondi>59) 
	{
		cout <<"valore ora invalido, riprovare please:\n";
		cin >>T2.secondi;
	}
	diffe1=T1.ora-T2.ora;
	diffe2=T1.minuti-T2.minuti;
	diffe3=T1.secondi-T2.secondi;
	cout <<"i due orari hanno una differenza di: \n" <<abs(diffe1) <<" ore " <<abs(diffe2) <<" minuti " <<abs(diffe3) <<" secondi" <<endl;
}