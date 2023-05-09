#include "liste.h"

int main()
{
	list lista,lista2;
	int elementi;
	lista=newcell(5);
	lista=push_front(lista,4);
	lista=push_back(lista,7);
	lista=insert_after(lista,6,1);
	//lista=clear(lista);
	//print(lista);
	elementi=length(lista);
	cout <<"numero elementi lista: " <<elementi <<endl;
	//lista=remove(lista,0);
	//lista=remove_cont(lista,4);
	//cout <<is_present(lista,5) <<endl <<at(lista,8) <<endl;
	//lista=sort(lista);
	print(lista);
	lista=ordered_insert(lista,3);
	//lista=reverse(lista);
	print(lista);
	//lista=unique(lista);
	lista2=newcell(1);
	lista2=push_front(lista2,2);
	lista2=push_front(lista2,8);
	print(lista2);
	lista=merge(lista, lista2);
	print(lista);
	lista2=nth_from_last(lista,0);
	cout <<lista2->info <<endl;
}