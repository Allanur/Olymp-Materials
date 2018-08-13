# include <iostream>
# include <stdio.h>
# include <limits.h>
# include <algorithm>

# define INF INT_MAX

using namespace std;
const int n = 900;
const int m = 8100;

int test, x, y, z, k;
int d[n+1][m+1], t[n+1][m+1], v[109];

int main ()
{
	fill(t[0], t[n+1], INF);
	fill(d[0], d[n+1], INF);
	
	t[0][0] = 1, d[0][0] = 0;
	
	for (int j = 9; j >= 0; j--)
		for (int i = 0; i <= n; i++)
			for (int h = 0; h <= m; h++)
				if (d[i][h] != INF && i+j <= n && h+j*j <= m && t[i][h]+1 <= t[i+j][h+j*j])
					d[i+j][h+j*j] = j, t[i+j][h+j*j] = t[i][h]+1;
	
	cin >> test;
	
	while(test--)
	{
		z = 0;
		cin >> x >> y;
		if (x>n || y>m || d[x][y]==INF) {cout << "No solution\n";continue;}
		
		while(d[x][y] && x && y)
		{
			k = d[x][y];
			v[z++] = k;
			x-=k, y-=k*k;
		}
		
		if (x || y || z>100)	{cout << "No solution\n";continue;}
		
		sort (v, v+z);
		for (int i = 0; i < z; i++)
			cout << v[i];
		cout << "\n";		
	}
	
	return 0;
}
