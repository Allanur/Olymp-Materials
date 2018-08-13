# include <iostream>
# include <stdio.h>
# include <algorithm>

# define maxn (int)1e5+9

using namespace std;

int n,s,z,l;
int dp[maxn], v[109], gel[maxn], t[maxn];

int main ()
{
	dp[0] = 1;
	
	cin >> s >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	
	for (int i = 1; i <= n; i++)
		for (int h = s; h >= 0; h--)
			if (dp[h] && h+v[i] <= s)
			{
				if (gel[h+v[i]]==0)
					gel[h+v[i]] = i;
				dp[h+v[i]] += dp[h];
			}
		
	if (dp[s]==0)
		cout << 0;
	else if (dp[s]>1)
		cout << -1;
	else
	{	
		z = gel[s];
		while(z)
			t[l++] = z, s -= v[z], z = gel[s];
		l--;
		
		for (int i = 1; i <= n; i++)
		{
			if (i==t[l])	l--;
			else 	cout << i << " ";
		}		
	}
	
	return 0;
}
