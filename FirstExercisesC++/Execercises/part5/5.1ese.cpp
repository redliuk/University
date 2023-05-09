#include <iostream>
#include <string>
#include <math.h>
using namespace std;
struct Person
{
	string name;
	string surname;
	string birthyear;
};
int main() 
{
	Person me,you;
	me.name="Bruce";
	me.surname="Wayne";
	me.birthyear="1939";
	you.name="Clark";
	you.surname="Kent";
	you.birthyear="1933";
	me=you;
	cout <<"il mio nome è:" <<me.name<< endl;
	cout <<"il mio cognome è:" <<me.surname <<endl;
	cout <<"il mio anno di nascita è:" <<me.birthyear <<endl;
}