#include <iostream>
#include <string>
#include <vector>
using namespace std;

void readVector(vector<int>& v);
void printVector(const vector<int>& v);
int SequentialSearch_vector(const vector<int>& v, int item);

int main()
{
	vector<int> v;
	int index;
	readVector(v);
	printVector(v);
	index=SequentialSearch_vector(v,3);
	cout <<"item in posizione:" <<index <<endl;
}

void readVector(vector<int>& v)
{
	int size;
	cout <<"Inserisci la dimensione della sequenza:\n";
	cin >>size;
	v.resize(size);
	for(int i=0; i<size; i++)
	{
		cout <<"v[" <<i <<"]" <<endl;
		cin >>v[i];
	}
}

void printVector(const vector<int>& v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout <<v[i] <<endl;
	}
}

int SequentialSearch_vector(const vector<int>& v, int item)
{
	int loc=-1;
	bool found=false;
	for(int i=0; i<v.capacity() || found==false; i++)
	{
		if(v[i]==item)
		{
			found=true;
			loc=i;
		}
	}
	return loc;
}