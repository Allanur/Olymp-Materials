#include <iostream>
using namespace std;
int main ()
{
	
int a,b,top;

cin>>a>>b;

top=a*2;

if(top<=b)

{cout<<'2'; return 0;}	

else if(top%b==0)

cout<<top/b;

else if(top%b!=0)

cout<<top/b+1;

getchar (); getchar ();
return 0;}
