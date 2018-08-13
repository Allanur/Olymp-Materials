# include <stdio.h>

int n,m,a,x;

int main ()
{
	scanf ("%d%d" ,&n ,&m);
	
	n=n-1,m=m-1;
	
	if ( n < m )	
		a=m;
	else
		a=n;
		
	for ( int i = 1; i <= a; i++ )	
		if ( n%i==0 && m%i==0 )
			x=i;
	
	a=(n+m)-x;
	
	printf ("%d" ,a);
	
return 0;	
}
