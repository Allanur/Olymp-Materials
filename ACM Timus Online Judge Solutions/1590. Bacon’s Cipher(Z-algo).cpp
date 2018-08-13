#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define ln(c) (int)c.length()
#define all(c) c.begin(), c.end()

using namespace std;

int Z[10009], sol;
string s, c;

void Z_function(int n)
{
	fill(Z, Z+n, 0);
	reverse(all(s));
	int l=0, r=0, mx=0;
	
	for (int i=1; i<n; i++)
	{
		if (i <= r)
			Z[i] = min(r-i+1, Z[i-l]);
			
		while(Z[i]+i < n && s[Z[i]] == s[Z[i]+i])
			Z[i]++;
			
		if (r < Z[i]+i-1)
			l=i, r=Z[i]+i-1;
			
		mx = max(mx, Z[i]);
	}
	sol += ln(s)-mx;
	reverse(all(s));
}

int main()
{
	cin >> c;
	
	for (int i=0; i<ln(c); i++)
	{
		s += c[i];
		Z_function(i+1);
	}
	printf("%d" ,sol);
}
