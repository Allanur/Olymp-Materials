#include <stdio.h>
#include <algorithm>

template <class T> inline bool isprime(T x) {
	if(x==2)
		return 1;
	
	if(x%2==0)
		return 0;
	
	for(T i=3; i*i<=x; i+=2)
		if(x%i==0)
			return 0;

	return 1;
}

using namespace std;

int t,n;

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		
		if(isprime(n))
		{
			printf("%d\n" ,n);
			continue;
		}
		
		if(isprime(n-2))
		{
			printf("%d %d\n" ,2 ,n-2);
			continue;
		}
		
		if(n&1)
		{
			printf("3 ");
			n -= 3;
		}
		
		for(int i=2; ; i++)
			if(isprime(i) && isprime(n-i))
			{
				printf("%d %d\n" ,i ,n-i);
				break;
			}
	}
}
