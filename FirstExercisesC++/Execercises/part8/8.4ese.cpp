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
void delete_d_array(dynamic_array& a);

int main()
{
	int size=0;
	dynamic_array arr;
	arr=new_d_array(size);
	try
	{
		delete_d_array(arr);
	}
	catch (string& err) {cout <<err;}
}

void delete_d_array(dynamic_array& a)
{
	string err="array di taglia 0\n";
	if (a.size==0) throw err;
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