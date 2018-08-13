# include <iostream>
# include <stdio.h>
# include <map>
# include <algorithm>

using namespace std;
struct ooo
{
	int a, b;
	char c;
} v[5009];

int n, m, z=1, mx, x, y;
int d[5009*2], D[5009*2];
map <int, int> M;
bool color[5009*2];

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].a >> v[i].b >> v[i].c;
		
		d[m++] = v[i].a;
		d[m++] = v[i].b;
	}
	
	d[m++] = 0;
	d[m++] = 1000000000;
	
	sort (d, d+m);
	
	for (int i = 0; i < m; i++)
		if (!M[d[i]])
			M[d[i]] = z, D[z++] = d[i];
			
	for (int i = 0; i < n; i++)
	{
		bool one = (v[i].c=='b' ? 1 : 0);;
		for (int h = M[v[i].a]; h < M[v[i].b]; h++)
			color[h] = one;
	}
		
	color[z-1] = 1;
	for (int i = 1; i < z; i++)
	{
		int k = i;
		while(!color[i])	i++;
		
		if (mx < D[i]-D[k])	mx = D[i]-D[k], x = D[k], y = D[i];
	}
	
	cout << x << " " << y;
	
	return 0;
}
