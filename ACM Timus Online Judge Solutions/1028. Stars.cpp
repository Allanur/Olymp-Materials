# include <iostream>
# include <stdio.h>
# include <algorithm>

# define maxn 15000+9
# define maxm 32001

using namespace std;

struct ooo
{
	int x, y;
	
	bool operator < (ooo z) const
	{
		if (x==z.x)
			return y < z.y;
		return x < z.x;
	}
} P[maxn];

int n;
int T[maxm*4];
int L[maxn];

void update (int x, int l, int r, int node)
{
	T[node]++;
	if (l==r)
		return;
	if (x <= (l+r)/2)
		update (x, l, (l+r)/2, node*2);
	else
		update (x, (l+r)/2+1, r, node*2+1);
}
int level (int x, int l, int r, int node)
{
	if (l==r)
		return T[node];
		
	if (x <= (l+r)/2)
		return level (x, l, (l+r)/2, node*2);
		
	else
		return level (x, (l+r)/2+1, r, node*2+1) + T[node*2];
}

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> P[i].x >> P[i].y;
		P[i].x++, P[i].y++;
	}
	
	sort (P, P+n);
	
	for (int i = 0; i < n; i++)
	{
		L[level(P[i].y, 1, maxm, 1)]++;
		update (P[i].y, 1, maxm, 1);
	}
	
	for (int i = 0; i < n; i++)
		cout << L[i] << "\n";
	
	return 0;
}
