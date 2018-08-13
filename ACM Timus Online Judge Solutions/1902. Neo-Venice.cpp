#include <stdio.h>

int n, t, s, ss;

int main()
{
	scanf("%d %d %d" ,&n ,&t ,&s);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d" ,&ss);
		
		printf("%.6lf " ,double(t+s+ss)/2);
	}
}
