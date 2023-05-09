//##################################################################################


struct dynamic_array 
{
	int* store;
	unsigned int size;
};


//##################################################################################


dynamic_array new_d_array(int size)
{
	if (size<=0) size=0;
	dynamic_array a;
	a.size=size;
	a.store=new int[size];
	return(a);
}

void read_d_array(const dynamic_array& a)
{
	int conta;
	for (conta=0; conta<a.size; conta++)
	{
		cout <<"inserire un valore: " <<endl;
		cin >>a.store[conta];
	}
}

void print_d_array(const dynamic_array& a)
{
	int conta;
	int *p;
	p=a.store;
	for (conta=0; conta<a.size; conta++)
	{
		cout <<*(a.store+conta) <<'\t';
	}
	cout <<endl;
}

void delete_d_array(dynamic_array& a)
{
	string err="array di taglia 0\n";
	if (a.size==0) throw err;
	if (a.size>0)
	{
		delete a.store;
		a.size=0;
		a.store=nullptr;
	}
}

int set_d_array(dynamic_array& a, int value, int index)
{
	string err="indice dato non accettabile\n";
	if (index<0 || index>=a.size)
	{
		throw err;
	}
	a.store[index]=value;
	return(value);
}

int get_d_array(dynamic_array& a, int index)
{
	int value;
	string err="indice dato non accettabile\n";
	if (index<0 || index>a.size)
	{
		throw err;
	}
	value=a.store[index];
	return(value);
}


//##################################################################################