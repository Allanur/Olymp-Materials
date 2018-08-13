# include <iostream>

using namespace std;

int n,a,sol;
int v[999];

int main ()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v[a]++;
	}
	
	for (int i = 600; i <= 700; i++)
		sol+=v[i]/4;
	
	cout << sol;
	
return 0;	
}
