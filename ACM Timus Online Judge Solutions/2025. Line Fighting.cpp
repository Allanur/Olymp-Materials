#include <stdio.h>

int team[10010];
int t, n, k, ans, sum;

int main()
{
	scanf("%d" ,&t);
	
	while(t--)
	{
		scanf("%d %d" ,&n ,&k);
		
		ans = sum = 0;
		
		for(int i=0; i<k && n>0; i += i==k-1 ? -i : 1,n--)
			team[i]++;
		
		for(int i=0; i<k; i++)
			ans += sum*team[i], sum+=team[i], team[i]=0;
		
		printf("%d\n" ,ans);
	}
}
