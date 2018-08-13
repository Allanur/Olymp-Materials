# include <stdio.h>
# include <limits.h>

# define min(x,y) (x > y ? y : x)

int n,z=0,sol=INT_MAX;
int v[29],f[29];

void fn (int x)
{
	if (x==n)
	{
		z = 0;
		for (int i = 0; i < n; i++)
			(f[i] ? z-=v[i] : z+=v[i]);
			
		if (z>=0)
			sol = min (sol,z);
		
		return;
	}
	for (int i = 0; i <= 1; i++)
		f[x] = i, fn (x+1);
}

int main ()
{
	
	scanf ("%d" ,&n);
	
	for (int i = 0; i < n; i++)		scanf ("%d" ,&v[i]);

	fn (0);

	printf ("%d" ,sol);

return 0;
}
