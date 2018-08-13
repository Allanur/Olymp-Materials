# include <iostream>
# include <algorithm>

using namespace std;

int n,sol,l,z=1;
int v[500009];

int main ()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort (v, v+n);
	
	for (int i = 0; i < n; i++)
	{
		if (v[i]==v[i+1])
			z++;
		else
		{
			if ( l < z)
				l = z, sol = v[i];
			z = 1;
		}
	}
	
	cout << sol;
	
return 0;	
}
