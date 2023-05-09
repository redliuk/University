#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int main() 
{
	char a,b;
	a='Z';
	b='Z';
	cout <<"inserire lettera maiuscola" <<endl;
	while (a>='A' && a<='Z')
	{
		cin >>a;
		if (a>='A' && a<='Z')
		{
			cout <<"lettera maiuscola accettata, inserire nuovo carattere: " <<endl;
			if (a<=b)
			{
				b=a;
			}
		}
	}
	cout <<"prima lettera in ordine alfabetico: " <<b <<endl;
}