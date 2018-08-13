# include <stdio.h>

int n, sol;
int dp[19][89];

int main ()
{
	scanf ( "%d" ,&n ); 	// cin >> n;
	
	for ( int i = 1; i <= 9; i++)	
		dp[1][i] = 1;
	
	for ( int i = 2; i <= 9; i++ )
		for ( int h = 0; h <= 9; h++ )
			for ( int j = 1; j <= 81; j++ )
				dp[i][h+j] += dp[i-1][j];
	
	dp[10][1] = 1;
	
	for ( int i = 1; i <= 10; i++ )
		sol += dp[i][n];
	
	printf ("%d" ,sol);		// cout << ans;

return 0;	
}
