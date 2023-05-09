#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int a,five,twfive,n;
	cout <<"inserire un valore positivo intero: \n";
	cin >>a;
	five=a/5;
	twfive=a/25;
	n=five+twfive;
	cout <<"il fattoriale del numero dato ha " <<n <<" zeri finali\n";
}