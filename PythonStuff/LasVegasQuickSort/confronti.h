#include<iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

int confronti = 0;
int valoreMedio(int iter, vector <int>seq);
vector < int > creaSeq();
void swap (vector < int >&v, int i, int j);
int partizione (vector < int >&v, int inizio, int fine);
void Quicksort (vector < int >&v, int inizio, int fine);
int LVQuickSort (vector < int >&v);
int main();