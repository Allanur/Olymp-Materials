# include <stdio.h>

int n,k,x,a,b;

int main ()
{
	scanf ("%d %d" ,&n,&k);
	
	for (int i = 0; i < n; i++)
	{
		scanf ("%d" ,&x);
		(x > k ? a+=x-k : b+=k-x);
	}
	
	printf ("%d %d" ,a,b);
	
return 0;	
}
