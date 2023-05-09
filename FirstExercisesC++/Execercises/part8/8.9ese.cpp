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

int main()
{
	int capacity=5;
	myvector v;
	create(v, capacity);
}

void create(myvector& v, int capacity)
{
	v.store=new int[capacity];
	v.capacity=capacity;
	v.size=0;
}