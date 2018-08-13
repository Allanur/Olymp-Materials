#include <bits/stdc++.h>												///Think Less Do More

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define lst(c) c[sz(c)-1]
#define sz(c) (int)c.size()
#define ln(c) (int)c.length()
#define all(c) c.begin(), c.end()
#define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

using namespace std;
typedef long long lld;
const int MAXN = 109;
typedef pair<int,int> pii;

lld cost;
vector <int> E[MAXN];
char v[MAXN][MAXN], c;
int n, d, a, last, prev=-1;
bool vis[MAXN], R[MAXN][MAXN];

void dfs(int node)
{
	if (vis[node])
		return;
	
	vis[node] = 1;
	
	last = node;
	
	tr(j, E[node])
		dfs(*j);
}

void dfs2(int node)
{
	vis[node] = 1;
	
	tr(j, E[node])
	{
		if (vis[*j] && !R[node][*j])
			v[node][*j] = v[*j][node] = 'd', R[node][*j] = R[*j][node] = 1, cost += d;
		
		else if (!R[node][*j])
		{
			R[node][*j] = R[*j][node] = 1;
			dfs2(*j);
		}
	}
}

int main ()
{ios_base::sync_with_stdio(false);
	
	memset(v, '0', sizeof(v));
	
	cin >> n >> d >> a;
	
	for (int i=1; i<=n; i++)
		for (int h=1; h<=n; h++)
		{
			cin >> c;
		
			if (c == '1')
				E[i].pb(h);
		}
	
	for (int i=1; i<=n; i++)
		if (!vis[i])
		{
			dfs(i);
		
			if (prev != -1)
			{
				E[prev].pb(last);
				E[last].pb(prev);
				cost += a;
				v[prev][last] = v[last][prev] = 'a';
			}
		
			prev = last;
		}
	
	memset(vis, 0, sizeof(vis));
	
	dfs2(1);
	
	cout << cost << "\n";
	
	for (int i=1; i<=n; i++)
	{
		for (int h=1; h<=n; h++)
			cout << v[i][h];
		cout << "\n";
	}
}

