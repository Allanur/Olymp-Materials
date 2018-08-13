# include <stdio.h>
# include <algorithm>
# include <limits.h>
# include <math.h>

# define MAXN (int)1e6

bool vis[MAXN+9];
int a,b,sol,out;
double min = LLONG_MAX;

int bolen ( int x )
{
	int till = ceil(sqrt(x)), i = 2, sol = 0, prev = 0, sum = 1;
	
	while ( i <= till )
	{
		if ( x%i==0 )
		{
			sum*=i;
			//printf ( "%d %d %d " ,i ,sum, prev );
			if ( prev!=i )
				sol += i;
			if ( prev!=sum && sum!=i )
				sol += sum;
			x/=i;
			prev = i;
		}
		else
			i++;
	}
	if ( x > 1 && prev!=x )
		sol += x;
	
	return sol;
}

int main ()
{
	scanf ( "%d%d" ,&a ,&b );
	if ( a==1 )
	{
		printf ( "1" );
		return 0;
	}
	for ( int i = 2; i <= MAXN; i++ )
		if ( !vis[i] )
			for ( int h = i*2; h <= MAXN; h+=i)
				vis[h] = 1;
				
	for ( int i = b; i >= a; i-- )
		if ( !vis[i] )
		{
			sol = i;
			break;
		}
	
	if ( sol!=0 )
		printf ( "%d" ,sol );
		
	else if ( sol==0 && ( b-a!=0 ) )
	{
		for ( int i = a; i <= b; i++ )
		{
			if ( i%2 )
			{
				double bl = (double)(bolen(i)+1-i)/i;
				if ( min > bl )
				{
					min = bl;
					out = i;
				}
			}
		}
		printf ( "%d" ,out );
	}
	else
		printf ( "%d" ,a );
		
return 0;	
}
