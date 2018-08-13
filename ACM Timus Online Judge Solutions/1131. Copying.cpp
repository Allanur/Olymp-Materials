# include <stdio.h>

long long n,m,c=1,z;

int main ()
{
		scanf ("%lld%lld" ,&n ,&m);
		
	while ( c<m )
	{
		c*=2;
		z++;
		
		if ( c>=n ) 
		{
			printf ("%lld" ,z);
			return 0;
		}
		
	}
	
	n-=c;
	
	if ( n%m==0 )
		printf ("%lld" ,n/m+z);
		
	else
		printf ("%lld" ,n/m+1+z);
	
return 0;	
}
