# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

int n;
int d[59];

int main ()
{
	d[1] = 1;
	d[2] = 1;
	d[3] = 2;
	
	cin >> n;
	
	for (int i = 4; i <= n; i++)
		d[i] = d[i-1]+d[i-3]+1;
	
	cout << d[n];
	
	return 0;
}
