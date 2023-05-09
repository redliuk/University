#include <iostream>
#include <string>
#include <math.h>
using namespace std;

char* x[3];

void  printChoice(char** var, string l,char& c);
char* proposeVar(string a, char& b);
char** selectVar(char& a, char& b, char& c);

int main()
{
	char a,b,c;
	char** p;
	a='a';	b='b';	c='c';
	p=selectVar(a,b,c); 
	printChoice(p,"a",a);
	printChoice(p+1,"b",b);
	printChoice(p+2,"c",c);
	cout <<"inizialmente a: " <<a <<" b: " <<b <<" c: " <<c <<endl;
	cout <<"ora cancello la variabile che hai scelto\n";
	if (*(p)!=nullptr) *(*(p))=' ';
	if (*(p+1)!=nullptr) *(*(p+1))=' ';
	if (*(p+2)!=nullptr) *(*(p+2))=' ';
	cout <<"ora a: " <<a <<" b: " <<b <<" c: " <<c <<endl;
}

char** selectVar(char& a, char& b, char& c) 
{
	char** p;
	p=x;
	string s1,s2,s3;
	cout <<"Scegli fra queste variabili potrai cambiare idea in seguito e sceglierne una diversa\n";
	s1="Vuoi la prima (y/n)? contiene;\n";
	*(p)=proposeVar(s1,a);
	s2="Preferisci la seconda (y/n)? contiene: \n";
	*(p+1)=proposeVar(s2,b);
	s3="Preferisci la terza (y/n)? contiene: \n";
	*(p+2)=proposeVar(s3,c);
	return(p);
	p=nullptr;
}

char* proposeVar(string a, char& b)
{
	char answer;
	cout <<a <<b <<endl;
	cin >>answer;
	if (answer=='y' || answer=='Y') return(&b);
	else return(nullptr);
}

void  printChoice(char** var, string l,char& c)
{
	if (*(var)==&c) cout <<"hai scelto " <<l <<endl;
}