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
void resize(myvector& v, int new_capacity);
void push_back(myvector& v, int x);
void safe_push_back(myvector& v, int x);

int main()
{
	int capacity=1;
	myvector v;
	create(v, capacity);
	try
	{
		safe_push_back(v,7);
	}
	catch (string& err)
	{
		cerr <<err;
	}
}

void create(myvector& v, int capacity)
{
	v.store=new int[capacity];
	v.capacity=capacity;
	v.size=1;
}

void resize(myvector& v, int new_capacity)
{
	myvector tmp;
	int conta=0;
	string err="nuova capacità inserita non accettabile\n";
	if (new_capacity<0) throw err;
	tmp.store=new int[new_capacity];
	if (v.size>new_capacity)
	{
		while(conta<new_capacity)
		{
			tmp.store[conta]=v.store[conta];
			conta++;
		}
		v.size=conta;
	}
	else
	{
		for(conta; conta<v.size; conta++)
		{
			tmp.store[conta]=v.store[conta];
		}
	}
	delete v.store;
	v.store=tmp.store;
	v.capacity=new_capacity;
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

void safe_push_back(myvector& v, int x)
{
	try
	{
		push_back(v,x);
	}
	catch(string& err)
	{
		cerr <<err;
		resize(v,-v.capacity*2);
	}
}