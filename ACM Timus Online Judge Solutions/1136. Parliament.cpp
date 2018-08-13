# include <iostream>

# define maxn 65535+9

using namespace std;

int n;
int v[3009];
int t[maxn][9];

void add (int x, int node, bool lr, int prev)
{
	if (node==0)
	{
		t[prev][lr] = x;
		return;
	}
	
	if (x > node)
		add (x, t[node][1], 1, node);
	else
		add (x, t[node][0], 0, node);
}

void out (int node, int par, bool lr)
{
	if (t[node][1])
		out (t[node][1], node, 1);
	
	else if (t[node][0])
		out (t[node][0], node, 0);
		
	else
	{
		cout << node << " ";
		t[par][lr] = 0;
		return;
	}
}

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	t[v[n]][4] = maxn;
	
	for (int i = n-1; i >= 1; i--)
		add (v[i], v[n], 0, 1);	
	
	for (int i = 1; i <= n; i++)
		out (v[n], v[n], 0);
	
	return 0;
}
