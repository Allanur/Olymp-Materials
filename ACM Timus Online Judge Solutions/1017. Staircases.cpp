# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

int n;
long long d[1009];

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

	cin >> n;
	
	d[0] = 1;
	
	for (int i = 1; i < n; i++)
		for (int h = n; h >= 0; h--)
			if (d[h])
				d[h+i] += d[h];
	
	cout << d[n];
	
	return 0;
}
