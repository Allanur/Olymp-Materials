# include <iostream>

using namespace std;

int a,b,c,d;

int main ()
{
	cin >> a >> b >> c >> d;
	
	if ( c==d )
	cout<<a;
	
	else if ( c<d && d-c==1 )
	cout<<(((d-c)+1)*b)+(((d-c)-1)*a);
	
	else if ( c>d && c-d==1 )
	cout<<((c-d)*a)+((((c-d)+1)*b)+a);
	
	else if ( c>d && c-d!=1 )
	cout<<(((c-d)+1)*a)+(((((c-d)+1)*2)-2)*b);		
	
	else if(c<d && d-c!=1)
	cout<<(((((d-c)+1)*2)-2)*b)+((d-c)-1)*a;
		
return 0;	
}
