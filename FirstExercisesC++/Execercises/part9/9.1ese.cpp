#include <iostream>
#include <string>
#include <vector>
using namespace std;

void readVector(vector<int>& v);
void printVector(const vector<int>& v);
void readVectorVariante(vector<int>& v);

int main()
{
	vector<int> v;
	readVector(v);
	readVectorVariante(v);
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

void readVectorVariante(vector<int>& v)
{
	string value;
	int i=0;
	int x;
	cout <<"Inizio inserimento, per interrompere digitare 'y'\n";
	cout <<"v[" <<i <<"]" <<endl;
	cin >>value;
	do
	{
		i++;
		x=stoi(value);
		v.push_back(x);
		cout <<"v[" <<i <<"]" <<endl;
		cin >>value;
	}
	while(value!="y");
}