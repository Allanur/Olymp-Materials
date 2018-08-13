# include <iostream>
# include <algorithm>
using namespace std;

int a,b,c,d;

int main ()
{
	cin>>a>>b>>c>>d;
	
	while ( a<=c )
	{
		a=a+b;
		
		if( a>=c )
		a=c;
		
		c=c-d;				
	}
	
	cout<<a;
	
return 0;	
}
