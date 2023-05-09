#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct Date 
{
	unsigned int anno; 
	unsigned int mese;
	unsigned int giorno;
};

int main()
{
	Date one;
	cout <<"inserire l'anno: \n";
	cin >>one.anno;
	cout <<"inserire il mese: \n";
	cin >>one.mese;
	if (one.mese>12) cout <<"numero del mese non accettabile\n";
	cout <<"inserire il giorno: \n";
	cin >>one.giorno;
	if(((one.anno%100==0) && (one.anno%400==0)) || ((one.anno%100!=0) && (one.anno%4==0))) {
		switch (one.mese)
		{
			case 1:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 2:
				if (one.giorno>29) cout <<"giorno non accettabile\n";
			case 3:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 4:
				if (one.giorno>30) cout <<"giorno non accettabile\n";
			case 5:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 6:
				if (one.giorno>30) cout <<"giorno non accettabile\n";
			case 7:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 8:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 9:
				if (one.giorno>30) cout <<"giorno non accettabile\n";
			case 10:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 11:
				if (one.giorno>30) cout <<"giorno non accettabile\n";
			case 12:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
		}
	}
	else 
	{
		switch (one.mese)
		{
			case 1:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 2:
				if (one.giorno>28) cout <<"giorno non accettabile\n";
			case 3:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 4:
				if (one.giorno>30) cout <<"giorno non accettabile\n";
			case 5:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 6:
				if (one.giorno>30) cout <<"giorno non accettabile\n";
			case 7:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 8:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 9:
				if (one.giorno>30) cout <<"giorno non accettabile\n";
			case 10:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
			case 11:
				if (one.giorno>30) cout <<"giorno non accettabile\n";
			case 12:
				if (one.giorno>31) cout <<"giorno non accettabile\n";
		}
	}
	if (one.anno<2019) {cout <<"data passata\n"; return(0);}
	if (one.anno>2019) {cout <<"data futura\n"; return(0);}
	if (one.anno=2019)
	{			
		if (one.mese<12) {cout <<"data passata\n"; return(0);}
		if (one.mese>12) {cout <<"data futura\n"; return(0);}
		if (one.mese=12) 
		{
			if (one.giorno<4) {cout <<"data passata\n"; return(0);}
			if (one.giorno>4) {cout <<"data futura\n"; return(0);}
			if (one.giorno=4) cout <<"oggi\n";
		}
	}

}