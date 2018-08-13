#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, sol=-127, mx;
int v[101][101];

int main()
{
	cin >> n;
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{
			cin >> v[i][j];
			v[i][j] += v[i][j-1];
		}
	
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
		{
			mx = 0;
			for (int h=1; h<=n; h++)
			{
				mx += (v[h][j]-v[h][i-1]);
				sol = max(sol, mx);
				if (mx<0)	mx = 0;
			}
		}
	
	cout << sol;
	
	return 0;
}
