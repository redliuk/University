#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string s1="Hello";
	string s2="World";
	cout <<"Debug: " <<static_cast<void*>(&s1) <<" " <<static_cast<void*>(&s2) <<endl;
	cout <<s1 <<" " <<s2 <<endl;
	string *p=&s1;
	cout <<"Debug: " <<p <<" " <<*p << endl;
	*p="Ciao";
	p=&s2;
	cout <<"Debug: " <<p <<" " <<*p << endl;
	*p="Mondo";
	cout <<s1 <<" " <<s2 <<endl;
}