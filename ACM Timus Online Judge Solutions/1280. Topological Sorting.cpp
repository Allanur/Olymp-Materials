# include <iostream>

# define maxm 100009

using namespace std;

struct ooo {
	int a,b;
} v[maxm];

int d[maxm];
int n,m,tlc;
bool one;
bool vis[maxm];

int find (int x)
{
	int l = 0;
	for (int i = 0; i < m; i++)
	{
		if (!vis[i] && v[i].b==x)
			return 1;
			
		if (!vis[i] && v[i].a==x)
			d[l++] = i;
	}
	for (int i = 0; i < l; i++)
		vis[d[i]] = 1;
	return 0;
}

int main ()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
		cin >> v[i].a >> v[i].b;
	
	for (int i = 0; i < n; i++)
	{
		cin >> tlc;

		if (!one && find(tlc))
			one = 1;
	}
	if (one)
		cout << "NO";
	else
		cout << "YES";
	
return 0;	
}
