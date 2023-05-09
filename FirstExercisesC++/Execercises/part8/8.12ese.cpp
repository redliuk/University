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
void set(myvector& v, int value, int index);

int main()
{
	int capacity=5;
	myvector v;
	create(v, capacity);
	try
	{
		set(v,7,2);
	}
	catch(string& err) {cerr <<err;}
}

void create(myvector& v, int capacity)
{
	v.store=new int[capacity];
	v.capacity=capacity;
	v.size=0;
}

void set(myvector& v, int value, int index)
{
	string err="indice dato non accettabile\n";
	if (index<0 || index>=v.size)
	{
		throw err;
	}
	v.store[index]=value;
}