#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct dynamic_array 
{
	int* store;
	unsigned int size;
};

dynamic_array new_d_array(int size);
void read_d_array(const dynamic_array& a);
int set_d_array(dynamic_array& a, int value, int index);
void print_d_array(const dynamic_array& a);

int main()
{
	int size=5;
	int set;
	dynamic_array arr;
	arr=new_d_array(size);
	read_d_array(arr);
	try
	{
		set=set_d_array(arr,5,2);
	}
	catch (string& err) {cout <<err;}
	print_d_array(arr);
}

dynamic_array new_d_array(int size)
{
	if (size<=0) size=0;
	dynamic_array a;
	a.size=size;
	a.store=new int[size];
	return(a);
}

void read_d_array(const dynamic_array& a)
{
	int conta;
	for (conta=0; conta<a.size; conta++)
	{
		cout <<"inserire un valore: " <<endl;
		cin >>a.store[conta];
	}
}

int set_d_array(dynamic_array& a, int value, int index)
{
	string err="indice dato non accettabile\n";
	if (index<0 || index>=a.size)
	{
		throw err;
	}
	a.store[index]=value;
	return(value);
}

void print_d_array(const dynamic_array& a)
{
	int conta;
	int *p;
	p=a.store;
	for (conta=0; conta<a.size; conta++)
	{
		cout <<*(a.store+conta) <<'\t';
	}
	cout <<endl;
}