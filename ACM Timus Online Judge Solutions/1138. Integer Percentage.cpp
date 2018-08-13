#include <stdio.h>

template <class T> void umax(T &x, T y) {if(x<y) x=y;}

const int MAXN = 10009;

using namespace std;

int n,s,ans;
int dp[MAXN];

int main()
{
	scanf("%d %d" ,&n ,&s);
	
	dp[s] = 1;
	
	for (int x=s; x<=n; x++)
		if (dp[x]!=0)
			for (int p=1; p<=100; p++)
				if ((x*p)%100==0 && x+(x*p/100)<=n)
					umax(dp[x+(x*p/100)], dp[x]+1);
	
	for (int x=s; x<=n; x++)
		umax(ans, dp[x]);
	
	printf("%d" ,ans);
}
