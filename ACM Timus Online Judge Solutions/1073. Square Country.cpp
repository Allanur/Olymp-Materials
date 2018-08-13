# include <iostream>
# include <limits.h>

# define MAXN 60009
# define INF INT_MAX

using namespace std;

int n;
int vis[MAXN],dp[MAXN];

int tap( int x )
{
	if ( x < 0 )	return -1;
	if ( vis[x] )	return dp[x];
	
	vis[x] = 1;
	
	for ( int i = 1; i <= 245; i++ )
	{
		int to = tap(x-(i*i));
		
		if ( to!=-1  &&  to+1 < dp[x] )	dp[x] = to+1;
	}
	
	return dp[x];
}

int main ()
{
	cin >> n;
	
	for ( int i = 1; i < 60001; i++ )	dp[i] = INF;
	
	vis[0]=1;
	
	cout << tap(n);
	
	return 0;
}
/*
for(int h=0; h<n; h++)
	for(int j=1; j<244; j++)
		if(dp[h] != INF  &&  j*j+h <= n  &&  dp[h]+1 < dp[j*j+h])
			dp[j*j+h] = dp[h]+1;
*/
