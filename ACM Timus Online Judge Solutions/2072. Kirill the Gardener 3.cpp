#include <stdio.h>
#include <algorithm>

#define ff first
#define ss second

const int MAXN = 100005;

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n, m;
pii a[MAXN];
ll dp[MAXN][2];
int occ[MAXN], L[MAXN], R[MAXN];

int main()
{
	scanf("%d" ,&n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d" ,&a[i].ff);
		a[i].ss = i;
	}
	
	sort(a, a+n);
	
	for(int i=0; i<n; i++)
	{
		occ[m]++;
		
		if(occ[m]==1)
			L[m] = a[i].ss;
		
		R[m] = a[i].ss;
		
		if(a[i].ff!=a[i+1].ff)
			m++;
	}
	
	dp[0][0] = R[0] + R[0] - L[0] + occ[0];
	dp[0][1] = R[0] + occ[0];
	
	for(int i=1; i<m; i++)
	{
		dp[i][0] = min(
			(ll)abs(L[i-1]-R[i]) + R[i] - L[i] + occ[i] + dp[i-1][0],
			(ll)abs(R[i-1]-R[i]) + R[i] - L[i] + occ[i] + dp[i-1][1]
		);
		
		dp[i][1] = min(
			(ll)abs(L[i-1]-L[i]) + R[i] - L[i] + occ[i] + dp[i-1][0],
			(ll)abs(R[i-1]-L[i]) + R[i] - L[i] + occ[i] + dp[i-1][1]
		);
	}
	
	printf("%lld" ,min(dp[m-1][0], dp[m-1][1]));
}
