#include <stdio.h>
#include <algorithm>

typedef long long lld;

int n, x1, y1, z1, x2, y2, z2, k, m;
int T[129][129][129];

void upd(int a, int b, int c, int d)	/// 3D BIT update
{
	for (int x=a; x<=n; x|=x+1)
		for (int y=b; y<=n; y|=y+1)
			for (int z=c; z<=n; z|=z+1)
				T[x][y][z] += d;
}
int tap(int a, int b, int c)			/// 3D BIT find
{
	int ret=0;
	for (int x=a; x>0; x=(x&(x+1))-1)
		for (int y=b; y>0; y=(y&(y+1))-1)
			for (int z=c; z>0; z=(z&(z+1))-1)
				ret += T[x][y][z];
	return ret;
}

int main()
{
	scanf("%d" ,&n);
	
	while(scanf("%d" ,&m))
	{
		if (m==3)	break;
		
		if (m==1)
		{
			scanf("%d %d %d %d" ,&x1,&y1,&z1,&k);
			upd(x1+1, y1+1, z1+1, k);
		}
		else
		{
			scanf("%d %d %d %d %d %d" ,&x1,&y1,&z1 ,&x2,&y2,&z2);
			x1++, y1++, z1++;
			x2++, y2++, z2++;
			printf("%d\n",tap(x2,y2,z2)-tap(x2,y2,z1-1)-tap(x2,y1-1,z2)-
			tap(x1-1,y2,z2)+tap(x1-1,y1-1,z2)+tap(x1-1,y2,z1-1)+
			tap(x2,y1-1,z1-1)-tap(x1-1,y1-1,z1-1));
		}
	}
	
	return 0;
}
