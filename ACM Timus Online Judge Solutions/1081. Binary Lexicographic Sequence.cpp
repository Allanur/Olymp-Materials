#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k, x;
int F[49], D[49], dp[49];

int main()
{
	scanf("%d %d" ,&n ,&k);
	
	F[0] = F[1] = F[2] = 1;
	dp[0] = 1, dp[1] = 2, dp[2] = 3;
	
	for (int i=3; i<44; i++)
		F[i] = F[i-1] + F[i-2], dp[i] = dp[i-1] + F[i];
	
	x = lower_bound(dp, dp+n+1, k) - dp;
	
	if (x > n)
	{
		printf("-1");
		return 0;
	}
	
	while(k > 0)
	{
		D[n-x] = 1;
		k -= F[x] + F[x-1];
		x = lower_bound(dp, dp+n+1, k) - dp;
	}
	
	for (int i=0; i<n; i++)
		printf("%d" ,D[i]);
}
