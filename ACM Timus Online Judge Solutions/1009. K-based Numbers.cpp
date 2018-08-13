# include <stdio.h>

int n,k,sol;
int dp[19][19];

int main ()
{
	scanf ( "%d%d" ,&n ,&k );
	
	for ( int i = 0; i < k; i++ )
		dp[0][i] = 1;
	
	for ( int i = 1; i < n; i++ )
		for ( int h = 0; h < k; h++ )
			for ( int j = 0; j < k; j++ )
				if ( h || j )
					dp[i][h] += dp[i-1][j];
	
	for ( int i = 1; i < 10; i++ )
		sol += dp[n-1][i];
	
	printf ( "%d" ,sol );
	
return 0;	
}

