#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

//nodo albero di codifica
struct nodo{
  char carattere;
  double prob;
  nodo* left;
  nodo* right;
};

//codifica e lunghezza carattere
struct codifica{
	char carattere;
	int cod[128];
	int lunghezza;
};

//costruisce l'array della codifica
bool visita(int* codifica, nodo* n, int i, char c){
  if (n->carattere == c){
    codifica[i+1]=-1;
    return true;
  }
  if (n->left != NULL){
    codifica[i]=1;
    if (visita(codifica,n->left, i+1, c)) return true;
  }
  if (n->right != NULL){
    codifica[i]=0;
    if (visita(codifica,n->right, i+1, c)) return true;
  }
  codifica[i]=-1;
  return false;
}

//chiama la visita ricorsiva partendo dalla radice
void visitaStarter (nodo* r, char c, int* codifica){
  int i=0;
  visita(codifica, r, i, c);
  return;
}

//cerca il carattere da codificare nel vettore
int cerca(vector<codifica> v, char c){
	int size =v.size();
	for (int i=0; i< size; i++){
		if (v[i].carattere==c){
			return i;
		}
	}
	return -1;
}

//ordina il vettore dei puntatori ai nodi
void ordina(vector<nodo*> &v){
  int size = v.size();
  nodo* aux;
  for (int i=1; i<size; ++i){
    for (int j=0; j<size-i; ++j)
      if(v[j]->prob<v[j+1]->prob){
         aux=v[j];
         v[j]=v[j+1];
         v[j+1]=aux;
      }
   }
}

//crea i nodi somma
void somma(vector<nodo*> &v){
  nodo* n = new nodo;
  n->carattere='\0';
  n->right = v.back();
  v.pop_back();
  n->left = v.back();
  v.pop_back();
  n->prob= n->right->prob+n->left->prob;
  v.push_back(n);
  ordina(v);
}

int main(){

  double prob, entropia=0, lunghezza=0, TotCar=0, CarDistiniti=0;
  string testo_input;
  fstream testo;
  map<char, double> lista;
  char carattere;
  vector <nodo*> v;
  vector<codifica> v1;

  cout << "nome testo in input:  ";
  cin >> testo_input;

  testo.open(testo_input, ios::in);
  while (testo.get(carattere))	++lista[carattere];

  for(auto elem : lista)
  {
     TotCar+= elem.second;
     CarDistiniti++;
  }

  if (CarDistiniti==0 || TotCar==0)
  {
     cout <<"testo non trovato" <<endl;
     return 0;
  }

  cout <<"numero totale caratteri = " <<TotCar <<endl;
  cout <<"numero caratteri distinti = " <<CarDistiniti <<endl;

  for(auto elem : lista)
  {
    prob=elem.second/TotCar;
    nodo* starter = new nodo;
    starter->carattere=elem.first;
    starter->prob=prob;
    starter->left= NULL;
    starter->right= NULL;
    v.push_back(starter);
    entropia+= prob*log2(1/prob);
  }

  ordina(v);
  while (v.size()>1)	somma(v);

  for(auto elem : lista)
  {
  	codifica aux;
	int codifica[64];
	char c = elem.first;
	prob= elem.second/TotCar;
	visitaStarter(v[0], c, codifica);
	aux.carattere=elem.first;
	int ind=0;
	cout <<c << " ";

	while (codifica[ind]!=-1)
	  {
	 	cout << codifica[ind];
	 	aux.cod[ind]=codifica[ind];
	 	ind++;
	  }
	  aux.lunghezza=ind;
	  v1.push_back(aux);

	  lunghezza += ind*prob;
	  cout  << "  lunghezza:" << ind << endl;
  }

	cout <<"entropia = " << entropia << endl;
	cout << "lunghezza attesa = " << lunghezza << endl;


	testo.close();
	testo.open(testo_input, ios::in);
	ofstream testout;
	testout.open("output.txt", ios::out);
	int index=0;
	while (testo.get(carattere)){
    index=cerca(v1, carattere);
    for (int i=0; i<v1[index].lunghezza; i++)
			testout << v1[index].cod[i];
  }

  if (lunghezza == entropia)
		cout << "entropia uguale alla lunghezza attesa: codifica ottimale" << endl;
	
	testo.close();
 	testout.close();
 	return 0;

}