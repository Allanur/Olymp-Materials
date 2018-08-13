# include <stdio.h>

int n, k, q;

int main ()
{
	scanf ("%d %d" ,&n ,&k);
	
	while (scanf("%d" ,&q) != EOF);
	
	printf ("%d" ,n*(n-1)/2-k);
	
	return 0;
}
