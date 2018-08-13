#include <stdio.h>
#include <algorithm>

const int maxn = 750009;

int n, m;
int L, R, k;
int Z[maxn];
char s[maxn];
char t[maxn];
char S[maxn];

int main()
{
	scanf("%d\n" ,&n);
	for (int i=0; i<n; i++)
		scanf("%c" ,&s[i]);
	scanf("\n");
	for (int i=0; i<n; i++)
		scanf("%c" ,&t[i]);
	
	m = n;
	t[m++] = 1;
	
	for (int i=0; i<n; i++)
		t[m++] = s[i];	
	for (int i=0; i<n; i++)
		t[m++] = s[i];
	
	Z[0] = m;
	for (int i=1; i<m; i++)
	{
		if (i>R)
		{
			L = R = i;
			while (R<m && t[R-L]==t[R])	R++;
			Z[i] = R-L, R--;
		}
		else
		{
			k = i-L;
			if (Z[k] < R-i+1)	Z[i] = Z[k];
			else
			{
				L = i;
				while (R<m && t[R-L]==t[R])	R++;
				Z[i] = R-L, R--;
			}
		}
	}
	
	for (int i=0; i<m; i++)
	{
		if (Z[i]==n)
		{
			printf("%d" ,(n - (i - (n+1)))%n);
			return 0;
		}
	}
	
	printf("-1");
	
	return 0;
}
