# include <iostream>
# include <stdio.h>
# include <vector>
# include <algorithm>

# define si(c) (int)c.size()
# define maxn (int)1e4+9
# define pb push_back

using namespace std;

int n, k, m, a, b, sol = -1;
vector < int > v[maxn];
bool vis[maxn];

void dfs(int x)
{
	if (vis[x])
		return;
	
	vis[x] = 1;
	
	for (int i = 0; i < si(v[x]); i++)
		dfs(v[x][i]);
}

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

	cin >> n >> k >> m;
	
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	for (int i = 0; i < m; i++)
		cin >> a >> b;
	
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i), sol++;
		
	cout << sol;
	
	return 0;
}
