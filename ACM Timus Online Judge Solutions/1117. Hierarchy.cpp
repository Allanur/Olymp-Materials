# include <iostream>
# include <stdio.h>
# include <math.h>
# include <algorithm>

using namespace std;
typedef long long lld;

int a, b;

int sol(int n)
{
	int ret = 0;
	
	for (int i = 30; i >= 0; i--)
		if (n-(1<<i) >= 0)
			ret += (n==(1<<i) ? (1<<i)-i-1 : (1<<i)-2),
			n -= (1<<i);
		
	return ret;
}

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

	cin >> a >> b;
	
	cout << abs(sol(a) - sol(b));
	
	return 0;
}
