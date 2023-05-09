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

int main()
{
	int capacity=5;
	myvector v;
	create(v, capacity);
	if(looks_consistent(v)) cout <<"my vector consistente\n";
	else cout <<"my vector non consistente\n";
}

void create(myvector& v, int capacity)
{
	v.store=new int[capacity];
	v.capacity=capacity;
	v.size=0;
}

bool looks_consistent(const myvector& v)
{
	if(v.store!=nullptr && 0<=v.size && v.size<=v.capacity && v.capacity>0)	return true;
	else return false;
}