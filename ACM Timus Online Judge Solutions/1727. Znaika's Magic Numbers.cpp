# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

int n, ret, sum, z;
int t[(int)1e5+9];

int gos (int x)
{
	ret = 0;
	while(x)
		ret += x%10, x/=10;
	return ret;
}

int main ()
{
	cin >> n;
	
	for (int i = (int)1e5-1; i >= 1; i--)
	{
		sum = gos(i);
		
		if (n-sum>=0)
			n -= sum, t[z++] = i;
			
		if (n==0)
		{
			cout << z << "\n";
			for (int h = 0; h < z; h++)
				cout << t[h] << " ";
			return 0;
		}
	}
	
	cout << -1;
	return 0;
}
