#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct dynamic_array 
{
	int* store;
	unsigned int size;
};

void delete_d_array(dynamic_array& a);
dynamic_array new_d_array(int size);
void read_d_array(const dynamic_array& a);
void print_d_array(const dynamic_array& a);

int main()
{
	int size=5;
	dynamic_array arr;
	arr=new_d_array(size);
	read_d_array(arr);
	delete_d_array(arr);
	print_d_array(arr);
}

void delete_d_array(dynamic_array& a)
{
	if (a.size>0)
	{
		delete a.store;
		a.size=0;
		a.store=nullptr;
	}
}

dynamic_array new_d_array(int size)
{
	if (size<=0) size=0;
	dynamic_array a;
	a.size=size;
	a.store=new int[size];
	return(a);
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

void read_d_array(const dynamic_array& a)
{
	int conta;
	for (conta=0; conta<a.size; conta++)
	{
		cout <<"inserire un valore: " <<endl;
		cin >>a.store[conta];
	}
}