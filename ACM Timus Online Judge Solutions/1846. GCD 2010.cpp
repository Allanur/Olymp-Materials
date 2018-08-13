# include <iostream>
# include <stdio.h>
# include <map>
# include <algorithm>

# define maxn (1<<17)

using namespace std;

int n, o;
int T[maxn*4], fr[maxn];;
char c;
map <int, int> M;

void upd (int x, int y, int l, int r, int node, bool one)
{
	if (l==r)
	{
		T[node] = (!one ? y : 0);
		return;
	}
	
	if (x <= (l+r)/2)
		upd(x, y, l, (l+r)/2, node*2, one);
		
	else
		upd(x, y, (l+r)/2+1, r, node*2+1, one);
		
	T[node] = __gcd(T[node*2], T[node*2+1]);
}

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c >> o;
		
		if (c=='+')
		{
			M.insert(make_pair(o, i));
			
			if (fr[M[o]]==0)
				upd(M[o], o, 1, maxn, 1, 0);
			fr[M[o]]++;
		}
		else
		{
			if (fr[M[o]]==1)
				upd(M[o], o, 1, maxn, 1, 1);
			fr[M[o]]--;
		}
		cout << max(T[1], 1) << "\n";
	}
	
	return 0;
}
