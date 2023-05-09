#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() 
{
	int i,p; 
	bool isprime[1001];
	for (i=0; i<1001; i++)
	{
		isprime[i]=true;
	}
	isprime[0]=false; isprime[1]=false;
		for(i=2; i<=500; i++)
		{
			isprime[p*i]=false;
		}
	for (i=2; i<1001; i++)
	{
		if (isprime[i]==true) 
			{
				for (p=3; i*p<1001; p++) isprime[i*p]=false;
			}
	}
	for (i=0; i<1001; i++)
	{
		if (isprime[i]==true) cout <<i <<" ";
	}
	cout <<endl;
}