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
void destroy(myvector& v);

int main()
{
	int capacity=5;
	myvector v;
	create(v, capacity);
	destroy(v);
}

void create(myvector& v, int capacity)
{
	v.store=new int[capacity];
	v.capacity=capacity;
	v.size=0;
}

void destroy(myvector& v)
{
	delete v.store;
	v.store=nullptr;
	v.capacity=0;
	v.size=0;
}