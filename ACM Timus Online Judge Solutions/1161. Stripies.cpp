# include <stdio.h>
# include <math.h>
# include <algorithm>

using namespace std;

int n;
int v[109];

double func ( int x )
{
	if ( x >= n-1 )
		return v[x];
		
	return 2 * sqrt ( v[x] * func ( x + 1 ) );
}

int main ()
{
	scanf ( "%d" ,&n );
	
	for ( int i = 0; i < n; i++ )
		scanf ( "%d" ,&v[i] );
	
	sort ( v, v+n );
	
	printf ( "%.2lf" ,func(0) );
	
return 0;	
}
