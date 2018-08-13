# include <iostream>

# define maxn 60009

using namespace std;

int n,mn,mx=-maxn;
int v[maxn];

int main ()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		
		v[i]+=v[i-1];
		
		mn = min (mn, v[i-1]);
		
		mx = max (mx, v[i]-mn);
	}
	
	cout << ( mx < 0 ? 0 : mx );
	
return 0;	
}
