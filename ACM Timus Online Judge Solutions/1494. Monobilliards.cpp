#include <stdio.h>

int st[100000];
int n, a, sz, p;

int main()
{
	scanf("%d" ,&n);
	
	while(n--)
	{
		scanf("%d" ,&a);
		
		while(p<a)
			st[sz++] = ++p;
		
		if(st[--sz]!=a)
		{
			printf("Cheater");
			return 0;
		}
	}
	
	printf("Not a proof");
}
