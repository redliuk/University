#include <iostream>
#include <string>
#include <vector>
using namespace std;

void readVector(vector<int>& v);
void printVector(const vector<int>& v);
vector<int> cat(vector<int> v1, vector<int> v2);

int main()
{
	vector<int> first,second,total;
	int index;
	readVector(first);
	readVector(second);
	total=cat(first,second);
	cout <<"primo vettore:  ";
	printVector(first);
	cout <<"secondo vettore:  ";
	printVector(second);
	cout <<"vettore concatenato risultante:  ";
	printVector(total);
}

void readVector(vector<int>& v)
{
	int size;
	cout <<"Inserisci la dimensione della sequenza:\n";
	cout <<"veranno accettati esclusivamente valori positivi\n";
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
		cout <<v[i] <<"  ";
	}
	cout <<endl;
}

vector<int> cat(vector<int> first, vector<int> second)
{
	int scamb,size;
	vector<int> total;
	for(int i=0; i<first.size(); i++)
	{
		total.push_back(first[i]);
	}
	for(int i=0; i<second.size(); i++)
	{
		total.push_back(second[i]);
	}
	return total;
}