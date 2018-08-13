#include <stdio.h>

using namespace std;

int t, a, b, cnt;

int main()
{
	scanf("%d" ,&t);
	
	while(t--)
	{
		cnt = 0;
		
		scanf("%d %d" ,&a ,&b);
		
		if (b%a!=0 || a>b)
		{
			printf("0\n");
			continue;
		}
		
		b /= a;
		int to = b;
		
		for (int i=2; i*i<=to; i++)
			while(b%i==0)
				cnt++, b/=i;
		
		printf("%d\n" ,cnt+1+(b>1));
	}
}
