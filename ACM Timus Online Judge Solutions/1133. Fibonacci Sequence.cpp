#include <stdio.h>												///Think Less Do More
#include <algorithm>

using namespace std;
typedef long long lld;

bool flag;
lld x, fx, y, fy, n;
lld F[2009], lo, hi, mid;

int main ()
{
	scanf("%lld %lld %lld %lld %lld" ,&x ,&fx ,&y ,&fy ,&n);
	
	x += 1000, y += 1000, n += 1000;
	
	if (x > y)
	{
		swap(x, y);
		swap(fx, fy);
	}
	
	F[x] = fx, F[y] = fy;
	
	lo = -2000000000, hi = 2000000000;
	
	while(lo <= hi && x+1<y)
	{
		mid = (lo+hi)/2, flag = 0;
		
		F[x+1] = mid;
		
		for (int i=x+2; i<=y; i++)
		{
			F[i] = F[i-1] + F[i-2];
			
			if (F[i] < -2000000000)
			{
				lo = mid+1;
				flag = 1;
				break;
			}
			if (F[i] > 2000000000)
			{
				hi = mid-1;
				flag = 1;
				break;
			}
		}
		
		if (flag)	continue;
		
		if (F[y] == fy)
			break;
		
		if (F[y] > fy)
			hi = mid-1;
		
		else
			lo = mid+1;
	}
	
	if (n < x)	for (int i=x-1; i>=n; i--)	F[i] = F[i+2] - F[i+1];

	else for (int i=y+1; i<=n; i++)	F[i] = F[i-2] + F[i-1];
	
	printf("%lld" ,F[n]);
}
