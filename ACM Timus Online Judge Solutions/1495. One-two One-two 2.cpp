#include <stdio.h>

int n, len;
int pw[3][31];
bool dp[31][1000001];

inline int f(int a, int b, int c) {
	return c - pw[a][b] + (pw[a][b]>c ? n : 0);
}

int main()
{
	scanf("%d" ,&n);
	
	for(int i=1; i<3; i++)
	{
		pw[i][1] = i%n;
		
		for(int h=2; h<31; h++)
			pw[i][h] = pw[i][h-1]*10%n;
	}
	
	dp[0][0] = 1;
	
	for(int i=1; i<=30; i++)
		for(int h=0; h<n; h++)
			dp[i][h] = dp[i-1][f(1,i,h)] || dp[i-1][f(2,i,h)];
	
	for(int i=30; i>0; i--)
		if(dp[i][0])
			len = i;
	
	if(len>0)
	{
		int h = len==1 ? n : 0;
		
		while(len > 1)
		{
			if(dp[len-1][f(1,len,h)])
				putchar('1'), h = f(1,len,h);
			else
				putchar('2'), h = f(2,len,h);
			len--;
		}
		
		putchar(h+'0');
	}
	else
		printf("Impossible");
}
