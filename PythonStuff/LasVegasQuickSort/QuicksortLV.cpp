#include "confronti.h"

ofstream fout("conteggioConfronti.txt");

void valoreMedioVarianza(int iter, vector <int>sequenza){
    //creo un vettore per contenere il numero di confronti per ogni run di quicksort
    vector < int >confrontiPerRun;
    float sommatoria = 0;
    double somma=0;
    int doppio = 0;
    int quintuplo = 0;

    //qua vado a ripetere l'esecuzione di quicksort e salvo le ripetizioni anche su un file di output
    //tramite il quale verrà costruito l'istogramma, inoltre conto i confronti totali
    for(int i = 0; i<iter; i++)
    {
        confrontiPerRun.push_back(LVQuickSort(sequenza));
        fout<<confronti<<endl;
        somma=somma+confronti;
        confronti=0;
    }

    double media = somma/iter;

    //calcolo la sommatoria della varianza subito dopo la varianza stessa
    for(int i = 0; i<confrontiPerRun.size(); i++)
    {
        sommatoria += sqrt((confrontiPerRun[i]-media)*(confrontiPerRun[i]-media));
    }
    float varianza = sommatoria/iter;

    // stimo empiricamente il numero di volte che l'agoritmo
    // effettua il doppio e il quintuplo del valor medio dei confronti.
    for(int i=0; i<iter; i++)
    {
        if(confrontiPerRun[i] >= media * 2) doppio++;
        if(confrontiPerRun[i] >= media * 5) quintuplo++;
    }

    cout << endl;
    cout << "La varianza e': " << varianza << endl;
    cout << "Il valore medio e': " << media << endl << endl;
    cout << "Stima empirica della probabilità in cui LVQuickSort effettua " << endl;
    cout << "il doppio del valor medio dei confronti: " << doppio/media << endl;
    cout << "il quintuplo del valor medio dei confronti: " << quintuplo/media << endl;
}

vector < int > creaSeq ()
{
    vector < int >sequenza;
    srand ((unsigned) time (NULL));
    for (int i = 0; i < 10000; ++i)
        sequenza.push_back (rand ());
    return sequenza;
}

void swap (vector < int >&v, int i, int j)
{
    int tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;
}

int partizione (vector < int >&v, int inizio, int fine)
{
  int pivot = inizio + rand () % (fine - inizio + 1);	
  swap (v, pivot, inizio);	
  int i = inizio + 1;
  for (int j = inizio + 1; j <= fine; ++j)
    {
      confronti++;
      if (v[j] < v[inizio])	
	{
	  swap (v, i, j);
	  ++i;
	}
    }
  swap (v, inizio, i - 1);
  return i - 1;
}


void Quicksort (vector < int >&v, int inizio, int fine)
{
  if (inizio < fine)
    {
      int pivot = partizione (v, inizio, fine);
      Quicksort (v, inizio, pivot - 1);
      Quicksort (v, pivot + 1, fine);
    }
}

int LVQuickSort (vector < int >&v)
{
  Quicksort (v, 0, v.size () - 1);
  
  return confronti;
}

int main ()
{
  valoreMedioVarianza(100000, creaSeq ());

  fout.close();
}
