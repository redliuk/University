#include <iostream>
#include <string>
#include <vector>
using namespace std;

void readVector(vector<int>& v);
void printVector(const vector<int>& v);
vector<int> reverse(vector<int> v);

int main()
{
	vector<int> v;
	int index;
	readVector(v);
	printVector(v);
	v=reverse(v);
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
		if (v[i]<0) break;
	}
}

void printVector(const vector<int>& v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout <<v[i] <<endl;
	}
}

vector<int> reverse(vector<int> v)
{
	int scamb;
	for(int i=0; i<(v.size()/2); i++)
	{
		scamb=v[v.size()-i-1];
		v[v.size()-i-1]=v[i];
		v[i]=scamb;
	}
	return v;
}