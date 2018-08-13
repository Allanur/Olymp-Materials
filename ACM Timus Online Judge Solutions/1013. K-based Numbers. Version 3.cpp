#include <stdio.h>
#include <string.h>

typedef long long ll;

ll n, k, m;

struct matrix
{	
	ll F[2][2], A[2][2];
	
	ll mul(ll a, ll b)
	{
		ll ret = 0;
		
		while(b)
		{
			if(b&1LL)
				ret = (ret + a) % m;
			
			a = (a+a)%m, b>>=1;
		}
		
		return ret;
	}
	
	void const operator *= (matrix T)
	{
		memset(A, 0LL, sizeof(A));
		
		for(int i=0; i<2; i++)
			for(int h=0; h<2; h++)
				for(int j=0; j<2; j++)
					A[i][h] = (A[i][h] + mul(F[i][j], T.F[j][h])) % m;
		
		memcpy(F, A, sizeof(A));
	}	
} dp, T;

int main()
{
	scanf("%lld %lld %lld" ,&n ,&k ,&m);
	
	dp.F[0][0] = dp.F[0][1] = 1LL;
	
	T.F[0][1] = 1LL;
	T.F[1][0] = T.F[1][1] = k-1LL;
	
	while(n)
	{
		if(n&1LL)
			dp*=T;
		
		T*=T, n>>=1;
	}
	
	printf("%lld" ,dp.F[0][0]);
}
