/**
* Segment Tree
**/
# include <iostream>
# include <stdio.h>
# include <algorithm>

# define MAXN 50009

using namespace std;

int k, n, H, mx, sol=1, jump;
int T[MAXN];

void upd(int x, int l, int r, int node)
{
	T[node]++;
	
	if (l==r)	return;
	
	if (x <= (l+r)/2)	upd(x, l, (l+r)/2, node*2);

	else 			upd(x, (l+r)/2+1, r, node*2+1);
}
int tap(int x, int l, int r, int node)
{
	if (l==r)	return T[node];
	
	if (x <= (l+r)/2)	return tap(x, l, (l+r)/2, node*2) + T[node*2+1];
	
	return tap(x, (l+r)/2+1, r, node*2+1);
}

int main()
{
	cin >> n >> k;
	
	for (int i=0; i<k; i++)
	{
		jump = 0;
		fill(T, T+50009, 0);
		
		for (int h=0; h<n; h++)
		{
			cin >> H;
			jump += tap(H, 1, n, 1);
			upd(H, 1, n, 1);
		}
		
		if (mx < jump)	mx = jump, sol = i+1;
	}
	
	cout << sol;
	
	return 0;
}

