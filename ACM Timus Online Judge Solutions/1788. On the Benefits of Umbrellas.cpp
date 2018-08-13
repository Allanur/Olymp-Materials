# include <stdio.h>
# include <limits.h>
# include <algorithm>

using namespace std;

int n, m, sum, sum1, l, sol = INT_MAX, b[109],g[109];

int main ()
{
	scanf ( "%d%d" ,&n ,&m );
	
	for ( int i = 0; i < n; i++ )		scanf ( "%d" ,&b[i] ), sum += b[i];
	
	for ( int i = 0; i < m; i++ )		scanf ( "%d" ,&g[i] ), sum1 += g[i];
	
	sort ( b, b+n );	sort ( g, g+m );
	
	for ( int i = 0; i < n/2; i++ )		swap ( b[i], b[n-i-1] );
	for ( int i = 0; i < m/2; i++ )		swap ( g[i], g[m-i-1] );
			
	for ( int i = 0; i < n+1; i++ )
	{
		sol = min ( sol, sum + ( sum1*l ) );
		if ( g[i] && b[i] )
			sum -= b[i], sum1 -= g[i], l++;
	}
		
	printf ( "%d" ,sol );
	
return 0;	
}
