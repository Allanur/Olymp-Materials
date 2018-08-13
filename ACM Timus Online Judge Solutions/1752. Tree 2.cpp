///(͡° ͜ʖ ͡°)	[̲̅$̲̅(̲̅ιοο̲̅)̲̅$̲̅] 
#include <bits/stdc++.h>

#define  fi			first
#define  se			second
#define  ppb		pop_back
#define  pb			push_back
#define  mp			make_pair
#define  sz(c)		(int)c.size()						/// size of vector
#define  ln(c)		(int)c.length()						/// length of string
#define  all(c)		c.begin(), c.end()
#define  rall(c)	c.rbegin(), c.rend()
#define  tr(i,c)	for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

using namespace std;
///ifstream fin("input_name");
///ofstream fout("output_name");
typedef double 	DL;										/// double
typedef long long LLD;									/// long long int
const int maxn = 20009;

int T[maxn];	//parent
int L[maxn];	//Level
int P[maxn][16];//2^x parent
int n, m, a, b, sol;
vector <int> E[maxn];	//Edge
pair <int, int> F[maxn][3]; //distance, node --> farthest node

void dfs1(int node, int prev)
{
	T[node] = prev;
	L[node] = L[prev]+1;
	F[node][0].se = node;
	tr(i, E[node])
	{
		int to = *i;
		
		if (to==prev)
			continue;
			
		dfs1(to, node);
		
		for (int j=0; j<2; j++)
			if (F[node][j].fi < F[to][0].fi + 1)
			{
				swap(F[node][j], F[node][j+1]);
				F[node][j] = mp(F[to][0].fi+1, F[to][0].se);
				break;
			}
	}
}
void dfs2(int node, int prev)
{
	if (prev!=0)
	{
		pair <int, int> tmp = F[prev][0];
		
		if (tmp.se==F[node][0].se)
			tmp = F[prev][1];
		
		tmp.fi++;
		
		for (int j=0; j<2; j++)
			if (F[node][j].fi < tmp.fi)
			{
				swap(F[node][j], F[node][j+1]);
				F[node][j] = tmp;
				break;
			}
	}
	tr(i, E[node])
		if (*i!=prev)
			dfs2(*i, node);
}

void process()
{
	T[1] = -1;
	memset(P, -1, sizeof P);
	for (int i=1; i<=n; i++)
		P[i][0] = T[i];
	for (int j=1; (1<<j)<=n; j++)
		for (int i=1; i<=n; i++)
			if (P[i][j-1]!=-1)
				P[i][j] = P[P[i][j-1]][j-1];
}
int lca(int p, int q)
{
	if (L[p] < L[q])
		swap(p, q);
		
	int lg = log2(L[p]);
	
	for (int i=lg; i>=0; i--)
		if (L[p]-(1<<i)>=L[q])
			 p = P[p][i];
	
	if (p==q)
		return p;
		
	for (int i=lg; i>=0; i--)
		if (P[p][i]!=-1 && P[p][i]!=P[q][i])
			p = P[p][i], q = P[q][i];
	
	return T[p];
}

int shiftup(int x, int y)
{
	int lg = log2(L[x]);
	
	for (int i=lg; i>=0; i--)
		if (L[x]-(1<<i)>=y)
			x = P[x][i];
		
	return x;
}

int main ()
{
	cin >> n >> m;
	for (int i=0; i<n-1; i++)
	{
		cin >> a >> b;
		E[a].pb(b);
		E[b].pb(a);
	}
	
	dfs1(1, 0);
	dfs2(1, 0);
	process();
	
	for (int i=0; i<m; i++)
	{
		cin >> a >> b;
		if (F[a][0].fi<b)
		{
			printf("0\n");
			continue;
		}
		
		int LCA = lca(a, F[a][0].se);
		int in = L[a] - L[LCA];
		int in1 = L[F[a][0].se] - L[LCA];
		if (in<b)
			a = F[a][0].se, b = in1 - (b-in);
		b = L[a] - b;
		
		sol = shiftup(a,b);
		printf("%d\n" ,sol);
	}
}
