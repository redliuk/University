#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Contact_Str
{
	string Name;
	string Surname;
	string PhoneNumber;
};

typedef vector<Contact_Str> PhoneBook;

void print(const PhoneBook& B);
vector<int> insert(vector<int> v, int i, int val);
void add(PhoneBook& B, ifstream& f);
void sortSurnames(PhoneBook& B);
int FindPos(const PhoneBook& B, string S);
bool isGreater(string a, string b);

int main()
{
	ifstream f;
	PhoneBook B;
	string S;
	int pos;
	f.open("rubrica");
	if(f.good()) cout <<"file aperto correttamente\n";
	add(B,f);
	if(f.eof())	cout <<"file letto correttamente\n";
	f.close();
	sortSurnames(B);
	print(B);
	cout <<"inserire Surname da trovare in rubrica:\n";
	cin >>S;
	pos=FindPos(B,S);
	cout <<"l'utente inserito è in posizione: " <<pos <<endl;
}

void print(const PhoneBook& B)
{
	for (int i=0; i<B.size(); i++)
	{
		cout <<B[i].Name <<" " <<B[i].Surname <<" " <<B[i].PhoneNumber <<endl;
	}
}

void add(PhoneBook& B,ifstream& f)
{
	Contact_Str C;
	while(!f.eof())
	{
		f >>C.Name >>C.Surname >>C.PhoneNumber;
		B.push_back(C);	
	}	
}

void sortSurnames(PhoneBook& B)
{
	Contact_Str scambio;
	int conta=0;
	int lettera=0;
	while(conta<B.size())
	{
		for(int i=conta; i<B.size()-1; i++)
		{
			if (isGreater(B[i].Surname, B[i+1].Surname))
			{
				scambio=B[i];
				B[i]=B[i+1];
				B[i+1]=scambio;
			}
		}
		conta++;
	}
}

bool isGreater(string a, string b)
{
	for(int lettera=0; lettera<a.size() && lettera<b.size(); lettera++)
	{
		if (tolower(a[lettera])!=tolower(b[lettera]))	return tolower(a[lettera])>tolower(b[lettera]);
	}
	return false;
}

int FindPos(const PhoneBook& B, string S)
{
	int i=0;

	while(!isGreater(B[i].Surname, S) && i<B.size())
	{
		if(!isGreater(B[i].Surname, S) && i<B.size() && S.size()!=b[i].Surname.size())
		{
			while(!isGreater(B[i].Surname, S) && i<B.size())
			{
				i++;
			}
		}
		i++;
	}
	if(i!=0)	return i-1;
	else return i;
}