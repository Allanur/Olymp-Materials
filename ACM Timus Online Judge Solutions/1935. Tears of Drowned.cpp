# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

int n, sol, mx;
int v[109];

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sol += v[i];
		mx = max (mx, v[i]);
	}
	
	cout << sol + mx;
	
	return 0;
}
