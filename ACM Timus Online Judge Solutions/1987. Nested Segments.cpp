#include <stdio.h>
#include <algorithm>

#define fi first
#define se second
#define INF 1000000009

using namespace std;
const int MAXN = 100009;
typedef pair<int,int> pii;

class SegTree {
	private:
	pii T[1<<19];
	
	void _inf()
	{
		for (int i=0; i<(1<<19); i++)
			T[i].fi = INF, T[i].se = -1;
	}
	
	void _set(int x, int y, int z, int k, int l, int r, int node)
	{
		if (r<x || y<l)
			return;
		
		if (x<=l && r<=y)
		{
			if (T[node].fi > z)
				T[node].fi = z, T[node].se = k;
			return;
		}	
		
		_set(x, y, z, k, l, (l+r)/2, node*2);
		
		_set(x, y, z, k, (l+r)/2+1, r, node*2+1);
	}
	
	pii _get(int x, int l, int r, int node)
	{
		if (l == r)
			return T[node];
		
		if (x <= (l+r)/2)
		{
			pii tmp = _get(x, l, (l+r)/2, node*2);
			return (T[node].fi < tmp.fi ? T[node] : tmp);
		}
		else
		{
			pii tmp = _get(x, (l+r)/2+1, r, node*2+1);
			return (T[node].fi < tmp.fi ? T[node] : tmp);
		}
	}
	
	public:
	void inf() {_inf();}
	void add(int x, int y, int z, int pos, int m) {_set(x, y, z, pos, 1, m, 1);}
	int get(int x, int m) {return _get(x, 1, m, 1).se;}
};

int n, m;
SegTree St;
int D[MAXN];
pair<int,int> v[MAXN];

int main()
{
	St.inf();
	
	scanf("%d" ,&n);
	
	for (int i=1; i<=n; i++)
		scanf("%d %d" ,&v[i].fi ,&v[i].se);
	
	scanf("%d" ,&m);
	
	for (int i=1; i<=m; i++)
		scanf("%d" ,&D[i]);
	
	for (int i=1; i<=n; i++)
	{
		int a = lower_bound(D+1, D+1+m, v[i].fi) - D;

		int b = upper_bound(D+1, D+1+m, v[i].se) - D - 1;
		
		St.add(a, b, v[i].se-v[i].fi, i, m);
	}
	
	for (int i=1; i<=m; i++)
		printf("%d\n" ,St.get(i, m));
}
