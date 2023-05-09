#include <string>
#include "graph.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int menu() 
{
    int scelta = -1;
    while (true)
    { 
        cout << "--------------------------------------------------------------------------\n";
        cout << "                                  MENU                                    \n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "1. Per inserire il CFG da file\n";
        cout << "2. Per stampare i cammini del CFG inserito da file\n";
        cout << "3. Per stampare il grafo corrispondente al CFG inserito da file\n";
        cout << "0. Uscita\n";
        cout << "\nImmetti la scelta e premi ENTER ---> ";
        cin >> scelta;
        cin.ignore();
        cout << "--------------------------------------------------------------------------\n";
        if (cin.fail() || scelta < 0 || scelta > 3) 
        {
            cout << "\nScelta non valida\n";
            cin.clear();
            cin.ignore();
            // Questa si rende necessaria a causa di un bug di glibc, prima o poi sparira'
            clearerr(stdin);
            continue;
        }
        return scelta;
    }
}

int main(){
	CFG::Graph g;
	string nomefile;
	int buget, scelta;
	CFG::Label inizio,fine;
	cout <<endl <<"laboratorio creato da: Luca Comparini		matricola:S4184885\n" <<endl;
	cout <<"tramite menu è possibile richieder più volte la stampa dei cammini di un CFG\n";
	cout <<"inoltre è possibile inserire nuovi CFG sovrascivendo il precedente\n";
	while (true)
    {
        // Visualizzazione menu e acquisizione scelta
        scelta = menu();

        // Se l'utente ha scelto "0" vuole uscire dal programma
        if (scelta == 0) break;

        switch (scelta)
        {
        	//inserimanto del CFG
            case 1:	{
			cout << "Inserisci il nome del file\n";
			cin >> nomefile;
			ifstream ifs(nomefile.c_str());
			if (!ifs) cout << "\nErrore apertura file, verifica di avere inserito un nome corretto\n";
			CFG::clearGraph(g);
			g=CFG::CreateEmptyGraph();
			CFG::readFromStream(g, ifs);
			cout <<endl <<"CFG inserito correttamente\n" <<endl;
			}break;

			//stampa cammini del CFG
			case 2:	{
			inizio=g->label;
			fine=searchEnd(g);
			cout <<"inserire il buget: \n";
			cin >>buget;
			CFG::findPathControll(inizio, fine, buget, g);
			}break;

			//stampa del grafo
			case 3:	{
			CFG::printGraph(g);
			}break;
		}
	}
}