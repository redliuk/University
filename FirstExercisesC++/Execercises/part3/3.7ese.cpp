#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	char c;
	int a;
	do
	{
	cout <<"inserire un valore intero positivo " <<endl;
	cin >>a;
	cout <<"nuova rappresentazione:" <<endl;
	for (int i=0; i<a; i++)
	{
		cout <<"|";
	}
	cout <<endl <<"digitare 's' oppure 'S' per terminare, qulunque altro carattere per continuare" <<endl;
	cin >>c;
	}
	while (c!='s' && c!='S');
}