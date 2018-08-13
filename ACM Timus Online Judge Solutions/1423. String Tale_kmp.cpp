#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 750000;

int n, m;
char p[maxn];
char t[maxn];
char text[maxn];
int F[maxn];
bool flag;

void bff()
{
	int j;
	for (int i=2; i<=m; i++)
	{
		j = F[i-1];		
		for (; ;)
		{
			if (p[j]==p[i-1])	{F[i] = j+1; break;}

			if (j==0)	{F[i] = 0; break;}

			j = F[j];
		}
	}	
}
void kmp()
{
	bff();
	
	int i=0, j=0;
	
	for (; ;)
	{
		if (j==n)	break;
		
		if (t[j]==p[i])
		{
			i++, j++;
			if (i==m)	
			{
				printf("%d" ,(m-(j-m))%m);
				flag = 1;
				return;
			}
		}

		else if (i>0)	i = F[i];

		else j++;
	}
}

int main()
{
	scanf("%d\n" ,&n);
	for (int i=0; i<n; i++)
		scanf("%c" ,&t[i]);
	scanf("\n");
	for (int i=0; i<n; i++)
		scanf("%c" ,&p[i]);
	m = n;
	for (int i=0; i<m; i++)
		t[n++] = t[i];
		
	kmp();
	
	if (!flag)
		cout << -1;
	
	return 0;
}
