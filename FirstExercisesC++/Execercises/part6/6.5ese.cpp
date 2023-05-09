#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

char first_letter ();

int main()
{
	char lettera;
	lettera=first_letter();
	cout <<"la prima lettera in ordine alfabetico è: " <<lettera <<endl;
}

char first_letter ()
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
	return(b);
}