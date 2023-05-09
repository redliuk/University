#include <iostream>
#include <string>
#include <vector>
using namespace std;

void readVector(vector<int>& v);
void printVector(const vector<int>& v);
void SelectionSort_vector(vector<int>& v);

int main()
{
	vector<int> v;
	readVector(v);
	printVector(v);
	SelectionSort_vector(v);
	printVector(v);
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

void SelectionSort_vector(vector<int>& v)
{
	int greatestIndex,scamb;
	for(int i=0; i<v.capacity(); i++)
	{
		greatestIndex=i;
		for(int j=i+1; j<v.capacity(); j++)
		{
			if(v[j]<v[greatestIndex])	greatestIndex=j;
		}
		scamb=v[i];
		v[i]=v[greatestIndex];
		v[greatestIndex]=scamb;
	}
}