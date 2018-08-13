#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAXN = 1009;

int par[MAXN], rank[MAXN], cnt[MAXN], deg[MAXN];

int Find(int x)
{
	if (x==par[x])	return x;
	return par[x] = Find(par[x]);
}

void Union(int u, int v)
{
	u = Find(u), v = Find(v);
	if (rank[u] < rank[v])
		par[u] = v;
	else
	{
		par[v] = u;
		if (rank[u]==rank[v])
			rank[u]++;
	}
}

int u, v;
bool odds=1;

int main()
{
	for (int i=0; i<MAXN; i++)
		par[i] = i, rank[i] = 0;
	
	while(scanf("%d %d" ,&u ,&v)==2)
	{
		Union(u, v);
		deg[u]++, deg[v]++;
	}
	
	for (int i=1; i<MAXN; i++)
		cnt[Find(i)] += deg[i];
	
	for (int i=0; i<MAXN; i++)
		if (cnt[i]&2)
			odds = 0;
	
	printf("%d" ,odds);
}
