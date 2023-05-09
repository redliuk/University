#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int dime,i,r;
	cout <<"inserire un valore positivo intero per la dimensione dell'array:\n";
	cin >>dime;
	r=dime-1;
	int source[dime];
	int dest[dime];
	for (i=0; i<dime; i++)
	{
		cout <<"inserire il valore numero " <<i <<endl;
		cin >>source[i];
	}
	for (i=0; i<dime; i++) 
	{
		dest[r]=source[i];
		r--;
	}
	cout <<"array source: ";
	for (i=0; i<dime; i++)
	{
		cout  <<source[i] <<" ";
	}
	cout <<endl <<"array dest: ";
	for (i=0; i<dime; i++)
	{
		cout  <<dest[i] <<" ";
	}
	cout <<endl;
}