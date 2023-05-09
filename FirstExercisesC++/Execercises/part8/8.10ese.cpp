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
void push_back(myvector& v, int x);

int main()
{
	int capacity=5;
	myvector v;
	create(v, capacity);
	try{
	push_back(v, 3);
	} catch(string& err) {cerr <<err;}
}

void push_back(myvector& v, int x)
{
	string err="my vector ha raggiunto la massima capacità\n";
	if(v.size>=v.capacity) throw err;
	if(v.size<v.capacity)
	{
		v.store[v.size]=x;
		v.size++;
	}
}

void create(myvector& v, int capacity)
{
	v.store=new int[capacity];
	v.capacity=capacity;
	v.size=0;
}