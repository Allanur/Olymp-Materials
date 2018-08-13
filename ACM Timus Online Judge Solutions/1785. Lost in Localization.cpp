#include <iostream>
using namespace std;
int main ()
{
int n;
cin>>n;
if(n>0 && n<5)	
	cout<<"few";
if(n>4 && n<10)
	cout<<"several";	
if(n>9 && n<20)	
	cout<<"pack";
if(n>19 && n<50)	
	cout<<"lots";
if(n>49 && n<100)		
	cout<<"horde";
if(n>99 && n<250)		
	cout<<"throng";	
if(n>249 && n<500)		
	cout<<"swarm";		
if(n>499 && n<1000)		
	cout<<"zounds";	
if(n>1000)
	cout<<"legion";
getchar (); getchar ();
return 0;	
}
