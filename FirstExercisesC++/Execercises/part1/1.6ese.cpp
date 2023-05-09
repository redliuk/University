#include <iostream>
#include <string>
using namespace std;
int main(){
int a,b,c,d;
   d=0;
   cout <<"inserire 3 valori interi: " <<endl;
   cin >>a >>b >>c;
   d=a;
   a=b;
   b=c;
   c=d;
   cout << "i valori scambiati sono:" <<a <<" " <<b <<" " <<c <<endl;
}