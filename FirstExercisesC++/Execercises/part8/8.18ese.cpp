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
bool looks_consistent(const myvector& v);
void destroy(myvector& v);
void set(myvector& v, int value, int index);
int get(const myvector& v, int index);
int pop_back(myvector& v);
void push_back(myvector& v, int x);
void resize(myvector& v, int new_capacity);
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
	catch (string& err)	{cerr <<err;}
	catch (string& err0)	{cerr <<err0;}
}

void create(myvector& v, int capacity)
{
	v.store=new int[capacity];
	v.capacity=capacity;
	v.size=1;
}

bool looks_consistent(const myvector& v)
{
	if(v.store!=nullptr && 0<=v.size && v.size<=v.capacity && v.capacity>0)	return true;
	else return false;
}

void destroy(myvector& v)
{
	string err0="vettore dato non consistente\n";
	if(!looks_consistent(v))	throw err0;
	delete v.store;
	v.store=nullptr;
	v.capacity=0;
	v.size=0;
}

void set(myvector& v, int value, int index)
{
	string err0="vettore dato non consistente\n";
	if(!looks_consistent(v))	throw err0;
	string err="indice dato non accettabile\n";
	if (index<0 || index>=v.size)
	{
		throw err;
	}
	v.store[index]=value;
}

int get(const myvector& v, int index)
{
	string err0="vettore dato non consistente\n";
	if(!looks_consistent(v))	throw err0;
	string err="indice dato non accettabile\n";
	if (index<0 || index>=v.size)
	{
		throw err;
	}
	return(v.store[index]);
}

int pop_back(myvector& v)
{
	string err0="vettore dato non consistente\n";
	if(!looks_consistent(v))	throw err0;
	string err="size my vector pari a 0\n";
	if(v.size==0) throw err;
	if(v.size>0)
	{
		return(v.store[v.size-1]);
		v.size--;
	}
}

void push_back(myvector& v, int x)
{
	string err0="vettore dato non consistente\n";
	if(!looks_consistent(v))	throw err0;
	string err="my vector ha raggiunto la massima capacità\n";
	if(v.size>=v.capacity) throw err;
	if(v.size<v.capacity)
	{
		v.store[v.size]=x;
		v.size++;
	}
}

void resize(myvector& v, int new_capacity)
{
	string err0="vettore dato non consistente\n";
	if(!looks_consistent(v))	throw err0;
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

void safe_push_back(myvector& v, int x)
{
	string err0="vettore dato non consistente\n";
	if(!looks_consistent(v))	throw err0;
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