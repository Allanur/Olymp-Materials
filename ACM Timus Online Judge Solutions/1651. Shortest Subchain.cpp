#include <stdio.h>
#include <algorithm>

#define fi first
#define se second
#define inf 100009
#define mp make_pair

using namespace std;
const int MAXN = 100009;
typedef pair<int,int> pii;

int n, m;
int E[MAXN], A[MAXN];
pii dp[MAXN], N[MAXN/10+1];

int main()
{
	scanf("%d" ,&n);

	for (int i=1; i<=n; i++)
		scanf("%d" ,&E[i]);
	
	fill(N+1, N+MAXN/10+1, mp(inf,-1));
	
	for (int i=1; i<=n; i++)
	{
		if (N[E[i]].fi > dp[i-1].fi+1)
			dp[i] = N[E[i]] = mp(dp[i-1].fi+1, i-1);
		else
			dp[i] = N[E[i]];
	}
	
	int to = n;
	
	while(to)
	{
		A[m++] = E[to];
		to = dp[to].se;
	}
	
	for (int i=m-1; i>=0; i--)
		printf("%d " ,A[i]);
}
