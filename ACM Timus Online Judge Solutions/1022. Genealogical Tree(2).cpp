#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

#define pb push_back
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

using namespace std;
const int maxn = 1009;

int n, a;
bool vis[maxn];
vector <int> order;
vector <int> E[maxn];

void toposort(int node)
{
	if (vis[node])
		return;
	
	vis[node] = 1;
	
	tr(i, E[node])
		toposort(*i);
	
	order.pb(node);
}

int main()
{
	cin >> n;
	
	for (int i=1; i<=n; i++)
	{
		while(1)
		{
			cin >> a;
			
			if (a==0)
				break;
				
			E[i].pb(a);
		}
	}
	
	for (int i=1; i<=n; i++)
		toposort(i);
	
	reverse(all(order));
	
	tr(i, order)
		cout << *i << " ";
}
