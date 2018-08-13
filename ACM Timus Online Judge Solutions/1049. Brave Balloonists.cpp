# include <iostream>
# include <math.h>

# define maxN (int)1e5+9

using namespace std;
typedef long long ll;

int n = 10,N,TiLL;
int v[maxN];
ll sol=1;

void prime (int x)
{
	int till = ceil(sqrt(x)), i = 2;
	while (i<=till)
	{
		if (x%i==0)
			v[i]++,x/=i;
		
		else
			i++;	
	}
	if (x>1)
		v[x]++;
	TiLL = max (TiLL, max(till,x));
}

int main ()
{
	
	for (int i = 0; i < n; i++)
	{
		cin >> N;
		prime(N);
	}
	
	for (int i = 2; i <= TiLL; i++)
		if (v[i])
			sol*=v[i]+1;
	
	cout << sol%10;
	
return 0;	
}
