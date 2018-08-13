# include <iostream>
# include <math.h>
# include <algorithm>

using namespace std;
typedef double dl;
const dl INF = 1e5;
const int H = 1e3+9;
const dl con = 141.421356237;

int n, m, k, a, b;
dl d[H][H];

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

	cin >> n >> m >> k;
	
	n++, m++;
	fill(d[0], d[H], 100);
	d[1][1] = 0;
	for (int i = 0; i <= n; i++)	d[i][0] = INF;
	for (int i = 0; i <= m; i++)	d[0][i] = INF;
	for (int i = 0; i <= n+1; i++)	d[i][m+1] = INF;
	for (int i = 0; i <= m+1; i++)	d[n+1][i] = INF;
	
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		a++, b++;
		d[a][b] = con;
	}
	
	for (int i = 1; i <= n; i++)
		for (int h = 1; h <= m; h++)
		{
			if (d[i][h]==100)
				d[i][h] += min(d[i][h-1], d[i-1][h]);
				
			else if (d[i][h]==con)
				d[i][h] += min(d[i][h-1]+100, min(d[i-1][h]+100, d[i-1][h-1]));		
		}
		
	k = d[n][m];
	
	cout << (k+0.5 < d[n][m] ? ceil(d[n][m]) : floor(d[n][m]));
	
	return 0;
}
