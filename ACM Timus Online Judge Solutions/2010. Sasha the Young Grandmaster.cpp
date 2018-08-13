# include <stdio.h>

int n, x, y, a, b;
int v[9];
int king[]={-1,-1,-1,0,-1,+1,0,+1,+1,+1,+1,0,+1,-1,0,-1};
int knight[]={-2,+1,-1,+2,+1,+2,+2,+1,+2,-1,+1,-2,-1,-2,-2,-1};
int bishop[]={-1,+1,+1,+1,+1,-1,-1,-1};

int main ()
{
	scanf("%d%d%d" ,&n,&x,&y);
	
	for (int i = 0; i < 16; i+=2)
	{
		a = x+king[i], b = y+king[i+1];
		if (a>=1 && a<=n && b>=1 && b<=n)	v[1]++;
	}
	for (int i = 0; i < 16; i+=2)
	{
		a = x+knight[i], b = y+knight[i+1];
		if (a>=1 && a<=n && b>=1 && b<=n)	v[2]++;
	}
	for (int i = 0; i < 8; i+=2)
	{
		a = x+bishop[i], b = y+bishop[i+1];
		while(a>=1 && a<=n && b>=1 && b<=n)
			v[3]++, a += bishop[i], b += bishop[i+1];
	}
	v[4] = 2*n-2;
	v[5] = v[3]+v[4];
	
	printf("King: %d\n" ,v[1]);
	printf("Knight: %d\n" ,v[2]);
	printf("Bishop: %d\n" ,v[3]);
	printf("Rook: %d\n" ,v[4]);
	printf("Queen: %d" ,v[5]);
	
	return 0;
}
