#include <iostream>
#include <string>
#include <vector>
using namespace std;

void readVector(vector<int>& v);
void printVector(const vector<int>& v);
vector<int> insert(vector<int> v, int i, int val);

int main()
{
	vector<int> v;
	int val,i;
	readVector(v);
	cout <<"vettore inserito: ";
	printVector(v);
	cout <<"digitare valore da inserire nella sequenza: \n";
	cin >>val;
	if(v.size()==0)
	{
		try{v=insert(v,i,val);}	catch(string& err)	{cout <<err;}	
	}
	else
	{
	cout <<"digitare la posizione in cui inserire il vettore: \n";
	cin >>i;
	try{v=insert(v,i,val);}	catch(string& err)	{cout <<err;}
	}
	cout <<"nuovo vettore: \n";
	printVector(v);
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

vector<int> insert(vector<int> v, int i, int val)
{
	string err="indice inserito non accettabile\n";
	if(v.size()==0) 
	{
		v.push_back(val);
		return v;
	}
	v.push_back(v[v.size()]);
	if(i<0 || i>v.size()+1) throw err;
	if(i==v.size()+1) 
	{
		v.push_back(val);
		return v;
	}
	for(int conta=v.size()-1; conta>i; conta--)
	{
		v[conta]=v[conta-1];
	}
	v[i]=val;
	return v;
}