#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	char a='d';
	cout <<"scegli il tuo colore preferito tra quelli proposti scrivendo l'iniziale del colore." <<endl;
	do 
	{
		cout <<"ecco i colori:\n" <<"arancione\n" <<"blu\n" <<"verde\n" <<"nero\n" <<"giallo\n";
		cin >>a;
		if (a=='a' || a=='b' || a=='v' || a=='n' || a=='g' || a=='A' || a=='B' || a=='V' || a=='N' || a=='G')
		{
			cout <<"colore scelto: " <<endl;
			switch (a)
			{
				case 'a':
					cout <<"colore scelto arancione" <<endl;
					return (0);
					break;
				case 'b':
					cout <<"colore scelto blu" <<endl;
					return (0);
					break;
				case 'v':
					cout <<"colore scelto verde" <<endl;
					return (0);
					break;
				case 'n':
					cout <<"colore scelto nero" <<endl;
					return (0);
					break;
				case 'g':
					cout <<"colore scelto giallo" <<endl;
					return (0);
					break;
				case 'A':
					cout <<"colore scelto arancione" <<endl;
					return (0);
					break;
				case 'B':
					cout <<"colore scelto blu" <<endl;
					return (0);
					break;
				case 'V':
					cout <<"colore scelto verde" <<endl;
					return (0);
					break;
				case 'N':
					cout <<"colore scelto nero" <<endl;
					return (0);
					break;
				case 'G':
					cout <<"colore scelto giallo" <<endl;
					return (0);
					break;
			}		
		}
	}
	while (a!='a' && a!='b' && a!='v' && a!='n' && a!='b' && a!='A' && a!='B' && a!='V' && a!='N' && a!='G');
}