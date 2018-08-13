# include <stdio.h>
# include <vector>
# include <algorithm>
using namespace std;

long long n,x,a=1,b=1;
vector < long long > v,v1;

void func ( int y )
{
	if ( binary_search( v1.begin(), v1.end(), y) )
		printf ("1");		
	else
		printf ("0");
		printf (" ");
}

int main ()
{
	scanf ("%lld" ,&n);
	v.resize(n);
	
	for ( int i = 0; i < n; i++ )
	{
		scanf ("%lld" ,&v[i]);
		if ( x < v[i] )
			x=v[i];
	}
	
	v1.push_back(a);
	a=2;
	
	while ( a<=x )
	{				
		v1.push_back(a);
		b++;
		a+=b;
	}
	a=0;
	for ( int i = 0; i < n; i++ )
	{
		a=v[i];
		func ( a );
	}
	
return 0;
}
