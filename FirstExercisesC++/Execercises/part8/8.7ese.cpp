#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;

struct dynamic_array 
{
	int* store;
	unsigned int size;
};

dynamic_array new_d_array(int size);
void fread_d_array(const dynamic_array& a, ifstream& f);

int main()
{
	int size=5;
	ifstream f;
	
	f.open("file_per_ese7-8.txt");
	if(f.good()) cout <<"file aperto correttamente\n";
	dynamic_array arr;
	arr=new_d_array(size);
	fread_d_array(arr,f);
	if(f.eof()) cout <<"file letto fino alla fine\n";
	for(int i=0; i<size; i++)
	{
		cout <<arr.store[i] <<endl;
	}
	f.close();
}

dynamic_array new_d_array(int size)
{
	if (size<=0) size=0;
	dynamic_array a;
	a.size=size;
	a.store=new int[size];
	return a;
}

void fread_d_array(const dynamic_array& a, ifstream& f)
{
	for (int conta=0; conta<a.size; conta++)
	{
		f >>a.store[conta];
	}
}