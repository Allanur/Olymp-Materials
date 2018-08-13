#include <string>
#include <stdio.h>
#include <algorithm>

#define fi first
#define se second
#define mp make_pair

using namespace std;
const int maxn = 100009;
typedef pair <int, int> Tree;
typedef pair <string, int> worval;

Tree A[11];
int n, m, val;
Tree T[1<<20];
worval D[maxn];
string W[maxn], uu;
char word[16], u[16];

void update(int x, int y, int l, int r, int node)
{
	if(l==r)
	{
		T[node] = mp(x, y);
		return;
	}
	
	if(x <= (l+r)/2)
		update(x, y, l, (l+r)/2, node*2);
	
	else
		update(x, y, (l+r)/2+1, r, node*2+1);
	
	
	if(T[node*2].se >= T[node*2+1].se)
		T[node] = T[node*2];
	
	else
		T[node] = T[node*2+1];
}

Tree tap(int a, int b, int l, int r, int node)
{
	if(a<=l && r<=b)
		return T[node];
		
	if (r<a || b<l)
		return mp(0, 0);
	
	Tree x = tap(a, b, l, (l+r)/2, node*2);	

	Tree y = tap(a, b, (l+r)/2+1, r, node*2+1);	
	
	if (x.se >= y.se)
		return x;
	
	return y;
}

int main()
{
	scanf("%d" ,&n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%s %d" ,word ,&val);
		
		D[i] = mp(word, val);		
	}
	
	sort(D, D+n);
	
	for(int i=0; i<n; i++)
	{
		W[i] = D[i].fi;
		update(i+1, D[i].se, 1, n, 1);
	}
	
	scanf("%d" ,&m);
	
	for(int i=0; i<m; i++)
	{
		scanf("%s" ,u);
		uu = u;
		
		int l = lower_bound(W, W+n, uu) - W + 1;

		int r = upper_bound(W, W+n, uu+"zzzzzzzzzzzzzzz") - W;
		
		for(int h=0; h<min(r-l+1, 10); h++)
		{
			A[h] = tap(l, r, 1, n, 1);
			
			printf("%s\n" ,W[A[h].fi-1].c_str());
			
			update(A[h].fi, 0, 1, n, 1);
		}
		
		for(int h=0; h<min(r-l+1, 10); h++)			
			update(A[h].fi, A[h].se, 1, n, 1);
		
		if (i!=m-1)
			printf("\n");
	}
}
