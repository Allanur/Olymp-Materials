# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

int n;
int d[19], f[19];

int main ()
{
	f[0] = 1;
	for (int i = 1; i <= 10; i++)
		f[i] = f[i-1]*i;
	
	d[0] = 1;
	for (int i = 1; i <= 10; i++)
		for (int h = 1; h <= i; h++)
			d[i] += d[i-h] * (f[i]/(f[h]*f[i-h]));
	
	while(1)
	{
		cin >> n;
		if (n==-1)
			break;
		cout << d[n] << "\n";
	}
	
	return 0;
}
