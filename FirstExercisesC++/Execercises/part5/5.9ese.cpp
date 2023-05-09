#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
struct Data
{
	int gg,mm,aa;
};
struct Studente
{
	int matricola,voto;
	string nome;
	string cognome;
	Data data;
};
int main() 
{
	cout <<"inserire il numero di studenti da ordinare, per favore inserire almeno 3 studenti" <<endl;
	int a;
	cin >>a;
	Studente array[a];
	Studente change[1];
	int i,c=0;
	for (i=0; i<a; i++) 
	{
		cout <<"inserire dati studente " <<i <<endl;
		cout <<"matricola: "<<endl;
		cin >>array[i].matricola;
		cout <<"nome: " <<endl;
		cin >>array[i].nome;
		cout <<"cognome: " <<endl;
		cin >>array[i].cognome;
		cout <<"data di nascita in forma gg/mm/aa: " <<endl;
		cin >>array[i].data.gg >>array[i].data.mm >>array[i].data.aa;
		cout <<"voto: " <<endl;
		cin >>array[i].voto;
	}
	while (c<a) 
	{
		for (i=0; i<a-1; i++) 
		{
			if ((array[i].data.aa<array[i+1].data.aa) || (array[i].data.aa==array[i+1].data.aa && array[i].data.mm<array[i+1].data.mm) || (array[i].data.aa==array[i+1].data.aa && array[i].data.mm==array[i+1].data.mm && array[i].data.gg<array[i+1].data.gg))
			{
				change[0]=array[i+1]; array[i+1]=array[i]; array[i]=change[0];
			}
		}
		c++;
	}
	cout <<"i dati studenti in ordine decrescente di età: " <<endl;
	for (i=a-1; i>=0; i++) 
	{
		cout <<"dati studente " <<i <<endl;
		cout <<"matricola: " <<array[i].matricola <<endl;
		cout <<"nome: " <<array[i].nome <<endl;
		cout <<"cognome: " <<array[i].cognome <<endl;
		cout <<"data di nascita in forma gg/mm/aa: " <<endl;
		cout <<array[i].data.gg <<"/" <<array[i].data.mm <<"/" <<array[i].data.aa <<endl;
		cout <<"voto: " <<array[i].voto <<endl;
	}
}