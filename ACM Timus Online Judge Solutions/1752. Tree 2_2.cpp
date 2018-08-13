#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

using namespace std;
const int MAXN = 20009;

int n,q,u,v,d;
vector <int> E[MAXN];
pair<int,int> F[MAXN][3];
int L[MAXN],T[MAXN], P[MAXN][15];

void dfs1(int node, int prev)
{
	T[node] = prev;
	L[node] = L[prev]+1;
	F[node][0] = mp(0, node);
	
	tr(j, E[node])
	{
		int to = (*j);
		
		if (to==prev)
			continue;
			
		dfs1(to,node);
		
		for (int i=0; i<2; i++)
		{
			if (F[node][i].ff < F[to][0].ff+1)
			{
				swap(F[node][i], F[node][i+1]);
				F[node][i] = mp(F[to][0].ff+1, F[to][0].ss);
				break;
			}
		}
	}
}

void dfs2(int node, int prev)
{
	if (prev!=0)
	{
		pair<int,int> newf;
		
		if (F[prev][0].ss!=F[node][0].ss)
			newf = mp(F[prev][0].ff+1, F[prev][0].ss);
		
		else
			newf = mp(F[prev][1].ff+1, F[prev][1].ss);
		
		for (int i=0; i<2; i++)
		{
			if (F[node][i].ff < newf.ff)
			{
				swap(F[node][i], F[node][i+1]);
				F[node][i] = newf;
				break;
			}
		}
	}
	
	tr(j,E[node])
		if ((*j)!=prev)
			dfs2((*j),node);
}

void precalc()
{
	for (int i=1; i<=n; i++)
		P[i][0] = T[i];	
	for (int j=1; (1<<j)<=n; j++)
		for (int i=1; i<=n; i++)
			P[i][j] = P[P[i][j-1]][j-1];
}

int lca(int p, int q)
{
	if (L[p] < L[q])
		swap(p, q);
	
	for (int j=14; j>=0; j--)
		if (L[p]-(1<<j)>=L[q])
			p = P[p][j];
	
	if (p==q)
		return p;
	
	for (int j=14; j>=0; j--)
		if (P[p][j]!=0 && P[p][j]!=P[q][j])
			p=P[p][j], q=P[q][j];
	
	return T[p];
}

int shiftup(int x, int y)
{
	for (int j=14; j>=0; j--)
		if (L[x]-(1<<j)>=y)
			x = P[x][j];
	return x;
}

int main()
{
	scanf("%d %d" ,&n ,&q);
	
	for (int i=1; i<n; i++)
	{
		scanf("%d %d" ,&u ,&v);
		
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	dfs1(1,0);
	dfs2(1,0);
	precalc();
	
	while(q--)
	{
		scanf("%d %d" ,&v ,&d);
		
		if (F[v][0].ff < d)
		{
			printf("%d\n" ,0);
			continue;
		}
		
		int lc = lca(v, F[v][0].ss);
		int lf = L[v] - L[lc];
		int rt = L[F[v][0].ss] - L[lc];
		
		if (lf < d)
			v=F[v][0].ss, d=rt-(d-lf);
		
		d = L[v] - d;
		
		printf("%d\n" ,shiftup(v, d));
	}
}
