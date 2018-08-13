# include <iostream>
# include <stdio.h>
# include <string.h>
# include <algorithm>

# define MOD 1000000009

using namespace std;
typedef long long int lld;

int n;
lld sol;
lld v[100], v1[100];
bool pr[1009];

void three_prime_numbers()
{
	for (int i = 101; i < 998; i+=2)
	{
		pr[i] = 1;
		for (int h = 2; h*h <= i; h++)
			if (!(i%h))	{pr[i] = 0; break;}
	}
}

int main()
{
	three_prime_numbers();
	
	for (int i = 1; i <= 9; i++)
		for (int h = 0; h <= 9; h++)
			v[i*10+h]++;
	
	cin >> n;
	
	for (int i = 3; i <= n; i++)
	{
		sol = 0;
		
		for (int h = 10; h < 100; h++)
			if (v[h])
				for (int j = 1; j <= 9; j+=2)
					if (pr[h*10+j])
						v1[(h%10)*10+j] += v[h]%MOD, sol += v[h];
		
		memcpy(v, v1, sizeof v1);
		memset(v1, 0, sizeof v1);
	}
	
	cout << sol%MOD;
	
	return 0;
}
