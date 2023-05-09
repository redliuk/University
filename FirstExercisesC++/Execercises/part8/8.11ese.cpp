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
int pop_back(myvector& v);

int main()
{
	int capacity=5;
	int value;
	myvector v;
	create(v, capacity);
	try{
	push_back(v, 3);
	value=pop_back(v);
	}
	catch(string& err) {cerr <<err;}
}

void create(myvector& v, int capacity)
{
	v.store=new int[capacity];
	v.capacity=capacity;
	v.size=0;
}

void push_back(myvector& v, int x)
{
	string err="my vector ha raggiunto la massima capacità\n";
	if(v.size==v.capacity) throw err;
	if(v.size<v.capacity)
	{
		v.store[v.size]=x;
		//v.size++;
	}
}

int pop_back(myvector& v)
{
	string err="size my vector pari a 0\n";
	if(v.size==0) throw err;
	if(v.size>0)
	{
		return(v.store[v.size-1]);
		v.size--;
	}
}