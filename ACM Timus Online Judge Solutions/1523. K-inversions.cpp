# include <iostream>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <algorithm>

using namespace std;
typedef long long lld;
const int H = (int)2e4+9;
const int mod = (int)1e9;

lld n, k, sol, tmp;
lld v[H], T[H*4], P1[H];

lld query (int x, int l, int r, int node)
{
	if (l==r)
		return T[node];
	
	if (x <= (l+r)/2)
		return query(x, l, (l+r)/2, node*2) + T[node*2+1];
		
	else
		return query(x, (l+r)/2+1, r, node*2+1);
}

void upd (int x, int l, int r, int node, lld z)
{
	T[node] += z;
	if (l==r)
		return;
	
	if (x <= (l+r)/2)
		upd(x, l, (l+r)/2, node*2, z);
		
	else
		upd(x, (l+r)/2+1, r, node*2+1, z);
}

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	
	fill (P1, P1+n+1, 1);
	
	for (int h = 2; h <= k; h++)
	{
		fill(T, T+H*4+1, 0);		
		for (int i = 1; i <= n; i++)
		{
			tmp = query(v[i], 1, n, 1);
			upd(v[i], 1, n, 1, P1[i]);
			P1[i] = tmp % mod;
		}
	}
	
	for(int i = 1; i <= n; i++)
		sol += P1[i]%mod;
	
	cout << sol%mod;		
	
	return 0;
}
