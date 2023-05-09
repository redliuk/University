#include <iostream>
#include <string>
#include <math.h>
using namespace std;

char* proposeVar(string a, char b);
char* selectVar(char& a, char& b, char& c);

int main()
{
	char *p=nullptr;
	char a,b,c;
	a='a';	b='b';	c='c';
	p=selectVar(a,b,c);
	if(p==&a) cout <<"Hai scelto: " <<a <<endl;
	if(p==&b) cout <<"Hai scelto: " <<b <<endl;
	if(p==&c) cout <<"Hai scelto: " <<c <<endl;
	cout <<"inizialmente a: " <<a <<" b: " <<b <<" c: " <<c <<endl;
	cout <<"ora cancello la variabile che hai scelto\n";
	*p=' ';
	cout <<"ora a: " <<a <<" b: " <<b <<" c: " <<c <<endl;

}

char* selectVar(char& a, char& b, char& c) 
{
	char *p=nullptr;
	cout <<"Scegli fra queste variabili potrai cambiare idea in seguito e sceglierne una diversa\n";
	s1="Vuoi la prima (y/n)? contiene;\n";
	p=proposeVar(s1, a);
	s2="Preferisci la seconda (y/n)? contiene: \n";
	p=proposeVar(s2, b);
	s3="Preferisci la terza (y/n)? contiene: \n";
	p=proposeVar(s3,c);
	return(p);
}

char* proposeVar(string a, char b)
{
	char answer;
	cout <<a <<b <<endl;
	cin >>answer;
	if (answer=='y' || answer=='Y') return(&b);
	else return(nullptr);
}