#include "liste.h"

//esercizio 10.1
list newcell(const TIPO cont)
{
	list lista=new cell;
	lista->info=cont;
	lista->next=nullptr;
	return lista;
}

//esercizio 10.2
list push_front(list & mylist, const TIPO cont)
{
	list temp=newcell(cont);
	temp->next=mylist;
	mylist=temp;
	return mylist;
}

//esercizio 10.3
list push_back(list & mylist, const TIPO cont)
{
	list cur=mylist;
	list temp=newcell(cont);
	if (mylist==nullptr)	mylist=temp;
	else
	{
		while(cur->next!=nullptr)
		{
			cur=cur->next;
		}
		cur->next=temp;
	}
	return mylist;
}

//esercizio 10.4
list insert_after(list mylist, TIPO cont, int n)
{
	list cur=mylist;
	list temp=newcell(cont);
	if(cur==nullptr)	mylist=temp;
	else
	{
		while(cur->next!=nullptr && n!=0)
		{
			cur=cur->next;
			n--;
		}
		temp->next=cur->next;
		cur->next=temp;
		return mylist;
	}
}

//esercizio 10.5
list clear(list mylist)
{
	if(mylist!=nullptr)
	{
		mylist->next=clear(mylist->next);
		delete mylist;
		mylist=nullptr;
	}
	return mylist;
}

//esercizio 10.6
void print(list mylist)
{
	cout <<"lista:\n";
	if(mylist==nullptr)	cout <<"lista vuota";
	while(mylist!=nullptr)
	{
		cout <<"[" <<mylist->info <<"]  ";
		mylist=mylist->next;
	}
	cout <<endl;
}

//esercizio 10.9
int length(list mylist)
{
	int conta=0;
	if(mylist==nullptr)	return 0;
	else
	{
		while(mylist!=nullptr)
		{
			mylist=mylist->next;
			conta++;
		}
		return conta;
	}
	//Quale modifica sarà necessaria alla struct cell e alle altre funzioni se vogliamo ottenere la stessa informazione in un tempo indipendente dal numero di elementi?
	//si può aggiunger un campo info2 alla struct cell contenente un contatore che aumenta ad ogni cella aggiunta.
}

//esercizio 10.10
list remove(list & mylist, int n)
{
	int controllo=n;
	list cur=mylist;
	list temp=mylist;
	if(n==0)
	{
		mylist=cur->next;
		delete cur;
		return mylist;
	}
	if(mylist==nullptr)
	{
		cout <<"operzione non possibile: lista vuota\n";
		return mylist;
	}
	while(cur->next!=nullptr && n>0)
	{
		temp=cur;
		cur=cur->next;
		n--;
	}
	if(n>0)
	{
		cout <<"operzione non possibile: numero elementi lista superato\n";
		return mylist;
	}
	else
	{
		temp->next=cur->next;
		delete cur;
		return mylist;
	}
}

//esercizio 10.11
list remove_cont(list & mylist, TIPO cont)
{
	list cur=mylist;
	list temp=mylist;
	while(mylist->info==cont)
	{
		mylist=mylist->next;
		delete cur;
		cur=mylist;
		temp=mylist;
	}
	while(temp->next!=nullptr)
	{
		if(cur->info==cont)
		{
			temp->next=cur->next;
			delete cur;
			cur=temp->next;
		}
		else
		{
			temp=cur;
			cur=cur->next;
		}
	}
	return mylist;
}

//esercizio 10.12
bool is_present(list mylist, TIPO cont)
{
	list cur;
	cur=mylist;
	while(cur->next!=nullptr)
	{
		if(cur->info==cont)	return true;
		cur=cur->next;
	}
}

//esercizio 10.13
cell * find_first(list & mylist, TIPO cont)
{
	list cur;
	cur=mylist;
	while(cur->next!=nullptr)
	{
		if(cur->info==cont)	return cur;
		cur=cur->next;
	}
	return nullptr;
}

//esercizio 10.14
cell * at(list mylist, int n)
{
	if(mylist==nullptr)	return nullptr;
	list cur;
	cur=mylist;
	while(cur->next!=nullptr && n>0)
	{
		cur=cur->next;
		n--;
	}
	if (n>0)	return nullptr;
	else	return cur;
}

//esercizio 10.15
list ordered_insert(list & mylist, TIPO cont)
{
	mylist=sort(mylist);
	list cur=mylist;
	if(mylist->info>cont)
	{
		push_front(mylist,cont);
		return mylist;
	}
	int conta=0;
	while(cur!=nullptr && cur->info<cont)
	{
		cur=cur->next;
		conta++;
	}
	mylist=insert_after(mylist,cont,conta-1);
	return mylist;
}

//esercizio 10.16
list reverse(list & mylist)
{
	int conta=length(mylist);
	list cur=mylist;
	list temp=newcell(mylist->info);
	for(conta; conta>1; conta--)
	{
		cur=mylist;
		mylist=mylist->next;
		temp=push_front(temp,mylist->info);
		delete cur;
	}
	mylist=nullptr;
	return temp;
}

//esercizio 10.17
list unique(list & mylist)
{
	list cur=mylist;
	list temp=newcell(mylist->info);
	while(mylist->next!=nullptr)
	{
		if(mylist->info!=mylist->next->info)	temp=push_back(temp,mylist->next->info);
		mylist=mylist->next;
	}
	delete cur;
	mylist=nullptr;
	return temp;
}

//esercizio 10.18
list merge(list mylist1, list mylist2)
{
	mylist1=sort(mylist1);
	mylist2=sort(mylist2);
	int conta=length(mylist2);
	for(conta; conta>0; conta--)
	{
		mylist1=ordered_insert(mylist1, mylist2->info);
		mylist2=mylist2->next;
	}
	return mylist1;
}

//esercizio 10.19
cell * nth_from_last(list mylist,int n)
{
	if(mylist==nullptr)	return nullptr;
	int conta=length(mylist);
	conta=conta-n;
	list cur=mylist;
	if(conta<0)	return nullptr;
	for(conta; conta>1; conta--)
	{
		cur=cur->next;
	}
	return cur;
}

//esercizio 10.20
list sort(list & mylist)
{
	list cur,temp;
	temp=mylist;
	TIPO scamb;
	while (temp->next!=nullptr)
	{
		cur=mylist;
		while(cur->next!=nullptr)
		{
			if(cur->info>cur->next->info)
			{
				scamb=cur->info;
				cur->info=cur->next->info;
				cur->next->info=scamb;
			}
			cur=cur->next;
		}
		temp=temp->next;
	}
	return mylist;
}