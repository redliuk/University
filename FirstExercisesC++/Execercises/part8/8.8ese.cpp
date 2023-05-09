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
void reverse_file(const string& f, const string& o);

int main()
{
	string nomefilein="file_per_ese7-8.txt";
	string nomefilout="file_dest";
	try
	{
	reverse_file(nomefilein,nomefilout);
	}
	catch(string& err)	{cout <<err;}
}

dynamic_array new_d_array(int size)
{
	if (size<=0) size=0;
	dynamic_array a;
	a.size=size;
	a.store=new int[size];
	return a;
}

void reverse_file(const string& nomefilein, const string& nomefilout)
{
	ifstream f;
	ofstream o;
	string err="impossibile aprire il file1\n";
	dynamic_array a;
	a=new_d_array(5);
	f.open(nomefilein);
	if(f.good()) cout <<"file1 aperto correttamente\n";
	if(!f.good()) throw err;
	o.open(nomefilout);
	if(f.good()) cout <<"file2 aperto correttamente\n";
	dynamic_array arr;
	arr=new_d_array(5);
	for (int conta=0; conta<a.size; conta++)
	{
		f >>a.store[conta];
	}
	for (int conta=arr.size-1; conta>=0; conta--)
	{
		o <<a.store[conta];
	}
	if(f.eof()) cout <<"file1 letto fino alla fine\n";
	f.close();
	o.close();
}