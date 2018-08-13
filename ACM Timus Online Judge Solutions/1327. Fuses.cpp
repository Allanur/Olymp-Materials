# include <stdio.h>

int n,m,z;

int main ()
{
	scanf ("%d%d" ,&n ,&m);
	
	for ( int i = n; i <= m; i++ )
		if ( i%2==1 )
			z++;
			
	printf ("%d" ,z);
	
return 0;	
}
