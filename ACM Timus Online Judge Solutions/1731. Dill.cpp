# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;
const int maxn = (int)1e9;

int n, m;

int main ()
{
	cin >> n >> m;
	
	for (int i = 1; i <= (n-1)*51+1; i+=51)
		cout << i << " ";
	cout << "\n";	
	for (int i = maxn; i > maxn-m; i--)
		cout << i << " ";
	
	return 0;
}
