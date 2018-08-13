# include <iostream>
# include <stdio.h>
# include <math.h>
# include <algorithm>

# define maxn 25009

using namespace std;

int n, m, k, a, b;
int d[maxn];
int t[maxn][19];

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	
	cin >> m;
	
	while(cin >> k)
	{
		if (k==-1)
			break;
		d[n++] = k;
	}
	///---------------------------------------------RMQ---------------------------------------------
	for (int i = 0; i < n; i++)
		t[i][0] = i;
		
	for (int j = 1; (1<<j) <= n; j++)
		for (int i = 0; i+(1<<j)-1 < n; i++)
			t[i][j] = (d[t[i][j-1]] >= d[t[i+(1<<(j-1))][j-1]] ? t[i][j-1] : t[i+(1<<(j-1))][j-1]);
	///---------------------------------------------RMQ---------------------------------------------
	
	a = 0, b = m-1;
	while(b < n)
	{
		k = log2(b-a+1);
				
		cout << max(d[t[a][k]], d[t[b-(1<<k)+1][k]]) << "\n";
		
		a++, b++;
	}
	
	return 0;
}
