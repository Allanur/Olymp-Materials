# include <stdio.h>
# include <math.h>
# include <algorithm>

typedef double dl;
struct ooo
{
	dl x, y;
} d[109];

int n;
dl r;

int main ()
{
	dl x1, x2, y1, y2;
	scanf("%d %lf" ,&n ,&r);
	r *= 2*M_PI;
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf" ,&d[i].x ,&d[i].y);
		if (i > 1)
		{			
			x1 = d[i-1].x, y1 = d[i-1].y;
			x2 = d[i].x, y2 = d[i].y;
			r += sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); 
		}
	}
	
	x1 = d[1].x, y1 = d[1].y;
	x2 = d[n].x, y2 = d[n].y;
	r += sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); 
	
	printf("%.2lf" ,r);
	
	return 0;
}
