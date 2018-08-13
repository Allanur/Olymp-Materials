# include <stdio.h>

long long n,a=0,b=1;


int main ()
{
	scanf ("%lld" ,&n);

	for ( int i = 1; i <= n; i++ )
	{
		b+=a;
		a=b-a;
		
	}
	
	printf ("%lld" ,a*2);
		
return 0;	
}
