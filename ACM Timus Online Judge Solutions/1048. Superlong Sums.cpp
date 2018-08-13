# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

int n;
int v[1000009][3];

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i][1] >> v[i][2];
		
	for (int i = n-1; i >= 0; i--)
	{
		v[i][0] += v[i][1]+v[i][2];		
		if (v[i][0] > 9) v[i-1][0] += v[i][0]/10, v[i][0] %= 10;
	}
	
	for (int i = 0; i < n; i++)
		cout << v[i][0];
	
	return 0;
}
