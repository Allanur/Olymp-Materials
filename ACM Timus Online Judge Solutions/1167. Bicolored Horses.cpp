# include <iostream>
# include <stdio.h>
# include <algorithm>

# define INF (int)1e6

using namespace std;

int n,k,b,w;
bool col[509];
int dp[509][509];

int main (){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> col[i];
		
	for (int i = 1; i <= n; i++)
		for (int h = 1; h <= k; h++)
			if ( i!=h )		dp[i][h] = INF;
	
	for (int i = 1; i <= n; i++){
		( col[i] ? b++ : w++ );
		dp[i][1] = b*w;
	}	
	
	for (int i = 2; i <= n; i++){
		for (int h = 2; h <= min(i,k); h++){
			b = 0, w = 0;
			
			for (int j = i; j >= 1; j--){
				( col[j] ? b++ : w++ );
				
				dp[i][h] = min (dp[i][h], b*w+dp[j-1][h-1]);			
			}
		}
	}
	
	cout << dp[n][k];
	
	return 0;
}
