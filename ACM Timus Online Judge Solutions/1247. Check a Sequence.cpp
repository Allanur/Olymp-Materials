#include <iostream>

using namespace std;

int s, n, sum, mn;
bool ok=true;

int main()
{
	cin >> s >> n;
	
	for (int i=1,x; i<=s; i++)
	{
		cin >> x;
		sum += x;
		
		if (sum-i-mn > n)
			ok = false;
		
		mn = min(mn, sum-i);
	}
	
	cout << (ok ? "YES" : "NO");
		
	return 0;
}
