#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct Cartesiana
{
	double re; double im;
};

struct Esponenziale
{
	double modulo; double fase;
};

struct Complex
{
	Cartesiana a; Esponenziale b;
};

int main()
{	
	Complex z,z1;
	Complex somma,differenza,prodotto,rapporto;
	cout <<"inserire valori primo numero complesso: \n" <<"parte reale: \n";
	cin >>z.a.re;
	cout <<"parte immaginaria: \n";
	cin >>z.a.im;
	z.b.modulo=sqrt(pow(z.a.re,2)-pow(z.a.im,2));
	cout <<"fase: \n";
	cin >>z.b.fase;
	cout <<"inserire valori secondo numero complesso: \n" <<"parte reale: \n";
	cin >>z1.a.re;
	cout <<"parte immaginaria: \n";
	cin >>z1.a.im;
	z1.b.modulo=sqrt(pow(z.a.re,2)-pow(z.a.im,2));
	cout <<"fase: \n";
	cin >>z1.b.fase;
	cout <<endl;
	
	somma.a.re=z.a.re+z1.a.re;
	somma.a.im=z.a.im+z1.a.im;
	somma.b.modulo=sqrt(pow(somma.a.re,2)+pow(somma.a.im,2));
	if (somma.a.im>0 && somma.a.re==0) somma.b.fase=M_PI/2;
	if (somma.a.im<0 && somma.a.re==0) somma.b.fase=-M_PI/2;
	if (somma.a.re>0) somma.b.fase=atan(somma.a.im/somma.a.re);
	if (somma.a.re<0 && somma.a.im>=0) somma.b.fase=atan(somma.a.im/somma.a.re)+M_PI;
	if (somma.a.re<0 && somma.a.im<0) somma.b.fase=atan(somma.a.im/somma.a.re)-M_PI;
	
	differenza.a.re=z.a.re-z1.a.re;
	differenza.a.im=z.a.im-z1.a.im;
	differenza.b.modulo=sqrt(pow(differenza.a.re,2)+pow(differenza.a.im,2));
	if (differenza.a.im>0 && differenza.a.re==0) differenza.b.fase=M_PI/2;
	if (differenza.a.im<0 && differenza.a.re==0) differenza.b.fase=-M_PI/2;
	if (differenza.a.re>0) differenza.b.fase=atan(differenza.a.im/differenza.a.re);
	if (differenza.a.re<0 && differenza.a.im>=0) differenza.b.fase=atan(differenza.a.im/differenza.a.re)+M_PI;
	if (differenza.a.re<0 && differenza.a.im<0) differenza.b.fase=atan(differenza.a.im/differenza.a.re)-M_PI;
	
	prodotto.a.re=z.a.re*z1.a.re-z.a.im*z1.a.im;
	prodotto.a.im=z.a.re*z1.a.im+z.a.im*z1.a.re;
	prodotto.b.modulo=sqrt(pow(prodotto.a.re,2)+pow(prodotto.a.im,2));
	if (prodotto.a.im>0 && prodotto.a.re==0) prodotto.b.fase=M_PI/2;
	if (prodotto.a.im<0 && prodotto.a.re==0) prodotto.b.fase=-M_PI/2;
	if (prodotto.a.re>0) prodotto.b.fase=atan(prodotto.a.im/prodotto.a.re);
	if (prodotto.a.re<0 && prodotto.a.im>=0) prodotto.b.fase=atan(prodotto.a.im/prodotto.a.re)+M_PI;
	if (prodotto.a.re<0 && prodotto.a.im<0) prodotto.b.fase=atan(prodotto.a.im/prodotto.a.re)-M_PI;

	rapporto.a.re=(z.a.re*z1.a.re+z.a.im*z1.a.im)/(pow(z1.a.re,2)+pow(z1.a.im,2));
	rapporto.a.im=(z.a.im*z1.a.re-z.a.re*z1.a.im)/(pow(z1.a.re,2)+pow(z1.a.im,2));
	rapporto.b.modulo=sqrt(pow(rapporto.a.re,2)+pow(rapporto.a.im,2));
	if (rapporto.a.im>0 && rapporto.a.re==0) rapporto.b.fase=M_PI/2;
	if (rapporto.a.im<0 && rapporto.a.re==0) rapporto.b.fase=-M_PI/2;
	if (rapporto.a.re>0) rapporto.b.fase=atan(rapporto.a.im/rapporto.a.re);
	if (rapporto.a.re<0 && rapporto.a.im>=0) rapporto.b.fase=atan(rapporto.a.im/rapporto.a.re)+M_PI;
	if (rapporto.a.re<0 && rapporto.a.im<0) rapporto.b.fase=atan(rapporto.a.im/rapporto.a.re)-M_PI;

	cout <<"SOMMA:\n";
	cout <<"forma algebrica: z=" <<somma.a.re <<"+ i*" <<somma.a.im <<endl;
	cout <<"forma Esponenziale: modulo " <<somma.b.modulo <<" fase " <<somma.b.fase <<endl <<endl;
	cout <<"DIFFERENZA:\n";
	cout <<"forma algebrica: z=" <<differenza.a.re <<"+ i*" <<differenza.a.im <<endl;
	cout <<"forma Esponenziale: modulo " <<differenza.b.modulo <<" fase " <<differenza.b.fase <<endl <<endl;
	cout <<"PRODOTTO:\n";
	cout <<"forma algebrica: z=" <<prodotto.a.re <<"+ i*" <<prodotto.a.im <<endl;
	cout <<"forma Esponenziale: modulo " <<prodotto.b.modulo <<" fase " <<prodotto.b.fase <<endl <<endl;
	cout <<"RAPPORTO:\n";
	cout <<"forma algebrica: z=" <<rapporto.a.re <<"+ i*" <<rapporto.a.im <<endl;
	cout <<"forma Esponenziale: modulo " <<rapporto.b.modulo <<" fase " <<rapporto.b.fase <<endl <<endl;
}