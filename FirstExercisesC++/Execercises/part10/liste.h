#include <iostream>
#include <string>
using namespace std;

typedef double TIPO;

struct cell {
double info;
cell* next;
};

typedef cell* list;

list newcell(const TIPO cont);
list push_front(list & mylist, const TIPO cont);
list push_back(list & mylist, const TIPO cont);
list insert_after(list mylist, TIPO cont, int n);
list clear(list mylist);
void print(list mylist);
int length(list mylist);
list remove(list & mylist, int n);
list remove_cont(list & mylist, TIPO cont);
bool is_present(list mylist, TIPO cont);
cell * find_first(list & mylist, TIPO cont);
cell * at(list mylist, int n);
list ordered_insert(list & mylist, TIPO cont);
list reverse(list & mylist);
list unique(list & mylist);
list merge(list mylist1, list mylist2);
cell * nth_from_last(list mylist,int n);
list sort(list & mylist);