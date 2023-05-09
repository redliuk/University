#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct myvector
{
	int size;
	int capacity;
	int* store;
};

void create(myvector& v, int capacity);
int get(const myvector& v, int index);

int main()
{
	int capacity=5;
	int value;
	myvector v;
	create(v, capacity);
	try
	{
		value=get(v,2);
	}
	catch(string& err) {cerr <<err;}
}

void create(myvector& v, int capacity)
{
	v.store=new int[capacity];
	v.capacity=capacity;
	v.size=0;
}

int get(const myvector& v, int index)
{
	string err="indice dato non accettabile\n";
	if (index<0 || index>=v.size)
	{
		throw err;
	}
	return(v.store[index]);
}