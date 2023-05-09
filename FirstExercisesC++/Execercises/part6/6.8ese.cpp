#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

void  print_menu (string choice1, string choice2, string choice3, string choice4);
void print_choice(int n, string ch1, string ch2, string ch3, string ch4);
int get_choice(int max);
int use_menu(string choice1, string choice2, string choice3, string choice4);

int main()
{
	int answer;
	string s1="prima scelta";
	string s2="seconda scelta";
	string s3="terza scelta";
	string s4="basta";
	do
	{
		answer=use_menu(s1,s2,s3,s4);
	} while (answer!=4);
}

void  print_menu (string choice1, string choice2, string choice3, string choice4)
{
	cout <<"1 " <<choice1 <<endl;
	cout <<"2 " <<choice2 <<endl;
	cout <<"3 " <<choice3 <<endl;
	cout <<"4 " <<choice4 <<endl;
}

void print_choice(int n, string ch1, string ch2, string ch3, string ch4)
{
	cout <<endl <<"Scelta effetuata: \n";
	switch (n)
	{
		case 1:
			cout <<ch1 <<endl;
		break;
		case 2:
			cout <<ch2 <<endl;
		break;
		case 3:
			cout <<ch3 <<endl;
		break;
		case 4:
			cout <<ch4 <<endl;
		break;
	}
}

int get_choice(int max)
{
	int scelta;
	do
	{
		cout <<"Inserisci una scelta fra 1 e " <<max <<endl;
		cin >>scelta;
	} while (scelta<1 || scelta>max);
	return (scelta);
}	

int use_menu(string choice1, string choice2, string choice3, string choice4)
{
	int n;
	print_menu(choice1,choice2,choice3,choice4);
	n=get_choice(4);
	print_choice(n,choice1,choice2,choice3,choice4);
	return (n);
}