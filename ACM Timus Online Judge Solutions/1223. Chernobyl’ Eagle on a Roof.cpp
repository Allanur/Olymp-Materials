# include <iostream>
# include <stdio.h>
# include <math.h>
# include <algorithm>

using namespace std;

int e, f;
int dp[1001][1001];	/// [egg][floor]

int main ()
{
	for (int i = 1; i < 1001; i++)
		dp[i][1] = 1, dp[1][i] = i;
	
	for (int i = 2; i < 1001; i++)
	{
		for (int h = 2; h < 1001; h++)
		{
			int tmp = 0;
			
			for (int j = 9; j >= 0; j--)
			{
				tmp += 1<<j;
				
				// f2 > f1
				// f1 = dp[i-1][h-tmp] 	[e-1][f-g]
				// f2 = dp[i][tmp-1]	[e][g-1]
				
				if (tmp >= h  ||  dp[i-1][h-tmp] <= dp[i][tmp-1])
					tmp -= 1<<j;
			}
			
			dp[i][h] = dp[i][tmp] + 1;
			
			//if(h > tmp  &&  dp[i][h] > dp[i-1][h-tmp] + 1)
				//dp[i][h] = dp[i-1][h-tmp] + 1;
		}
	}
	
	while(1){
		int a, b;
		
		scanf("%d %d",&a,&b);
		
		if(!a)	break;
		
		printf("%d\n",dp[a][b]);
	}
	
	return 0;
}
