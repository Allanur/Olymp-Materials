# include <stdio.h>
# include <algorithm>

int n, z;
bool one, vis[9][9];
int pos[]={-2,+1,-1,+2,+1,+2,+2,+1,+2,-1,+1,-2,-1,-2,-2,-1};

void dfs(int i, int h, int gi, int gh, int l)
{
	vis[i][h] = 1;
	
	for (int j = 0; j < 16; j+=2)
	{
		int a = i+pos[j], b = h+pos[j+1];
		if (a>=1 && a<=n && b>=1 && b<=n && !vis[a][b])
		{
			dfs(a, b, i, h, l+1);
			if (one)
			{
				if (gi)	printf("%c%d\n" ,gh+96 ,gi);
				return;
			}
		}
	}
	
	if (l==n*n)
	{
		printf("%c%d\n" ,h+96 ,i);		
		if (gi)	printf("%c%d\n" ,gh+96 ,gi);		
		one = 1;
	}
	else
		vis[i][h] = 0;		
}

int main ()
{
	scanf("%d" ,&n);
	
	dfs(1,1,0,0,1);
	
	if (!one)
		printf("IMPOSSIBLE");

	return 0;
}
