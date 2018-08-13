# include <iostream>

using namespace std;
typedef long long ll;

ll n,m,y;
bool one;

ll bigmod ( ll b, ll p, ll m )
{
	if (p==0)	return 1;
	
	else if (p%2==0) { ll x=bigmod(b,p/2,m); return (x*x)%m; }
	
	else 	return ( (b%m)*bigmod(b,p-1,m))%m;
	
}

int main ()
{
		cin >> n >> m >> y;
	
	for ( int i = 0; i <= m; i++ )
		if (bigmod(i,n,m)==y)	{cout << i << " "; one=1;}
	
	if (one==0)   cout << -1;
	
return 0;	
}
//	X^N % M = Y
