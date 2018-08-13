#include <stdio.h>
#include <algorithm>

using namespace std;

long long ans, x, n;

int main()
{
	scanf("%lld" ,&n);
	
	for (int i=0; i<n; i++)
	{
		scanf("%lld" ,&x);
		
		ans = __gcd(ans, x);
	}
	
	printf("%lld" ,ans);
}
