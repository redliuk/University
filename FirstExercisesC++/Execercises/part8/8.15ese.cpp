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

int main()
{
	int capacity=5;
	myvector v;
	create(v, capacity);
	try
	{
		resize(v,7);
	}
	catch (string& err)	{cerr <<err;}
}

void create(myvector& v, int capacity)
{
	v.store=new int[capacity];
	v.capacity=capacity;
	v.size=0;
}

void resize(myvector& v, int new_capacity)
{
	myvector tmp;
	int conta=0;
	tmp.store=new int[new_capacity];
	string err="nuova capacità inserita non accettabile\n";
	if (new_capacity<0) throw err;
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