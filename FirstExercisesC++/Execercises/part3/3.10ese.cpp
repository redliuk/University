#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	string a;
	float b;
	do
	{
		cout <<"inserire un valore" <<endl;
		cin >>b;
		cout <<"il valore dato è: " <<b <<endl;
		cout <<"continuare con l'inserimento?" <<endl;
		cin >>a;
		if (a=="no")
		{
			return(0);
		}
	}
	while (a!="no");
}