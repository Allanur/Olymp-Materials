# include <stdio.h>

int n,x;
int col[109];
bool v[109][109],vis[109];

void fn (int x, bool y)
{
	if (vis[x])
		return;
	
	vis[x] = 1;
	(y ? y = 0 : y = 1);

	for (int i = 1; i <= n; i++)
		if (v[x][i] && !vis[i])
			col[i] = y, fn(i,y);
}

int main ()
{
	scanf("%d" ,&n);
	
	for (int i = 1; i <= n; i++)
	{
		while (scanf("%d" ,&x))
		{
			if (x==0)
				break;
			v[i][x] = 1, v[x][i] = 1;
		}
	}
	
	vis[1] = 1;
	for (int i = 1; i <= n; i++)
		for (int h = 1; h <= n; h++)
			if (!vis[h] && v[i][h]) 
				col[h] = 1, fn (h,1);
	
	for (int i = 1; i <= n; i++)
		for (int h = 1; h <= n; h++)
			if (i!=h && v[i][h]==1 && col[i]==col[h]){
				printf ("-1");return 0;}

	for (int i = 1; i <= n; i++)
		printf("%d" ,col[i]);

return 0;
}

