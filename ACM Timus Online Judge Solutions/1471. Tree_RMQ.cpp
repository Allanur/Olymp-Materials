#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 50009;

int n, m, a, b, c, k, x, y;
int V[2*maxn], v, M[2*maxn][17];
int T[maxn], L[maxn], W[maxn], Fin[maxn];
vector < pair<int, int> > G[maxn];

void dfs_tree(int node, int prev, int weight)
{
	Fin[node] = v;
	V[v++] = node;
	T[node] = prev;
	L[node] = L[prev] + 1;
	W[node] = W[prev] + weight;
	
	for (int i=0; i<(int)G[node].size(); i++)
	{
		int to = G[node][i].first;
		
		if (to==prev)	
			continue;
		
		dfs_tree(to, node, G[node][i].second);
		
		V[v++] = node;
	}
}
void RMQ()
{
	for (int i=0; i<v; i++)
		M[i][0] = i;
	for (int j=1; (1<<j)<=v; j++)
		for (int i=0; i+(1<<j)-1<v; i++)
			M[i][j] = (L[V[M[i][j-1]]]<L[V[M[i+(1<<(j-1))][j-1]]] ? M[i][j-1] : M[i+(1<<(j-1))][j-1]);
}
int main()
{
	scanf("%d" ,&n);
	
	for (int i=1; i<n; i++)
	{
		scanf("%d %d %d" ,&a,&b,&c);
		G[a].push_back(make_pair(b,c));
		G[b].push_back(make_pair(a,c));
	}
	L[0] = -1;
	dfs_tree(0, 0, 0);
	RMQ();
	
	scanf("%d" ,&m);
	
	for (int i=0; i<m; i++)
	{
		scanf("%d %d" ,&a,&b);
		x = Fin[a],	y = Fin[b];
		
		if (x>y)	swap(x, y);

		k = log2(y-x+1);
		c = (L[V[M[x][k]]]<L[V[M[y-(1<<k)+1][k]]] ? V[M[x][k]] : V[M[y-(1<<k)+1][k]]);
		printf("%d\n" ,(W[a]-W[c]) + (W[b]-W[c]));
	}
}
