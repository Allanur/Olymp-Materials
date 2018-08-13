#include <stdio.h>

int T[400005];
int n, k, c=1;

void yasa(int l, int r, int v)
{
	if(l==r)
	{
		T[v] = 1;
		return;
	}
	
	int mid = (l+r)>>1;
	
	yasa(l, mid, v<<1);
	yasa(mid+1, r, v<<1|1);
	
	T[v] = T[v<<1] + T[v<<1|1];
}

int tap(int x, int l, int r, int v)
{
	if(l==r)
	{
		T[v] = 0;
		return l;
	}
	
	int mid = (l+r)>>1, ret;
	
	if(x<=T[v<<1])
		ret = tap(x, l, mid, v<<1);
	else
		ret = tap(x-T[v<<1], mid+1, r, v<<1|1);
	
	T[v] = T[v<<1] + T[v<<1|1];
	
	return ret;
}

int main()
{
	scanf("%d %d" ,&n ,&k);
	
	yasa(1, n, 1);
	
	for(int i=0; i<n; i++)
	{
		c = (c+k-1) % (n-i);
		
		if(!c)	c = n-i;
		
		printf("%d " ,tap(c,1,n,1));
	}
}
