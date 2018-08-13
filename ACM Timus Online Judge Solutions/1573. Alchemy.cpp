# include <iostream>
# include <stdio.h>
# include <string>
# include <algorithm>

using namespace std;

int n, b, r, y, ans = 1;
string s;

int main ()
{
	cin >> b >> r >> y >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s=="Blue")		ans *= b;
		else if (s=="Red")	ans *= r;
		else 				ans *= y;
	}
	
	cout << ans;
	
	return 0;
}
