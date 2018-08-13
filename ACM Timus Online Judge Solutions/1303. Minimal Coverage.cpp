# include <iostream>
# include <stdio.h>
# include <limits.h>
# include <algorithm>

# define INF INT_MAX

using namespace std;
struct ooo
{
	int x, y;
} v[100009], D[100009];

int M, n, nn, a, b;
int dp[5009];
int gel[100009], gel2[100009];

int oye(ooo a, ooo b)
{
	if (a.x==b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	fill(dp, dp+5009, INF);
	dp[0] = 0;
	
	cin >> M;
	while(cin >> a >> b && (a || b))
	{
		if (b<=0)	continue;
		v[n].x=a, v[n++].y=b;
	}
		
	sort (v, v+n, oye);
	
	for (int i=0; i<n; i++)
	{
		a = max(0, v[i].x), b = min(M, v[i].y);
		
		if (a>=M)	continue;
		
		if (dp[a]!=INF)
		{
			for (int h=a+1; h<=b; h++)
			{
				if (dp[h] > dp[a]+1)
				{
					dp[h] = dp[a]+1;
					gel[h] = a;
					gel2[h] = i;
				}
			}
		}
	}
	gel[0] = -1;
	if (dp[M]==INF)	{cout << "No solution"; return 0;}
	
	while(M>0)
	{
		D[nn].x = v[gel2[M]].x, D[nn++].y = v[gel2[M]].y,
		M = gel[M];
	}
	
	cout << nn << "\n";
	for (int i=nn-1; i>=0; i--)
		cout << D[i].x << " " << D[i].y << "\n";
	
	return 0;
}
