#include <stdio.h>
#include <algorithm>

#define ff first
#define ss second
#define mp make_pair

using namespace std;
typedef long long lld;
typedef pair<int,int> pii;

lld binpow(int a, int b, int c)
{
	if (b==0)
		return 1;
		
	lld _a = binpow(a, b/2, c);
	
	if (b&1ll)
		return _a * _a * a % c;
	
	return _a * _a % c;
}

int euler_inverse(int a, int m)
{
	return binpow(a, m-2, m);
}

pii factorize(int n)
{
	pii ans = mp(0,0);	
	
	for (int i=2; i*i<=n; i++)
	{
		while(n%i==0)
		{
			if (ans.ff==0)
				ans.ff = i;
			
			else
			 	ans.ss = i;
	
			n/=i;
		}
	}
	
	if (n>1)
		ans.ss = n;
	
	return ans;
}

int k, n;

int main()
{
	scanf("%d" ,&k);
	
	while(k--)
	{
		scanf("%d" ,&n);
		
		pii pq = factorize(n);
		
		int a = pq.ff * euler_inverse(pq.ff, pq.ss);
		
		int b = pq.ss * euler_inverse(pq.ss, pq.ff);
		
		printf("0 1 %d %d\n" ,min(a,b) ,max(a,b));
	}
}
