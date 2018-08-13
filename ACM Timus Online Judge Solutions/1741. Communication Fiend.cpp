# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;
typedef long long int lld;
const int H = 1e4+9;
const lld INF = 1e10+9;

struct ooo
{
	int a, b, c;
	string t;
} U[H];

int before (ooo x, ooo y)
{
	return x.a < y.a;
}

int n, m;
lld P[H], L[H];

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	fill(P, P+H, INF);
	fill(L, L+H, INF);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> U[i].a >> U[i].b >> U[i].c >> U[i].t;
	
	sort (U, U+m, before);
	
	P[1] = 0, L[1] = 0;
	for (int i = 0; i < m; i++)
	{
		if (U[i].t=="Pirated" || U[i].t=="Cracked")
		{
			if (P[U[i].a]!=INF)
				P[U[i].b] = min(U[i].c + P[U[i].a], P[U[i].b]);
				
			if (L[U[i].a]!=INF)
				P[U[i].b] = min(P[U[i].b], U[i].c + L[U[i].a]);
		}
		if (L[U[i].a]!=INF && (U[i].t=="Licensed" || U[i].t=="Cracked"))
		{
			if (L[U[i].a]!=INF)
				L[U[i].b] = min(U[i].c + L[U[i].a], L[U[i].b]);
		}
	}
	
	if (min(L[n], P[n])==INF)	cout << "Offline";
	else 	cout << "Online\n" <<min(L[n], P[n]);
	return 0;
}
