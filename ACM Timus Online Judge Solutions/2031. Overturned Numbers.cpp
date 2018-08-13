#include <stdio.h>

int n;
int a[] = {16, 06, 68, 88};

int main()
{
	scanf("%d" ,&n);
	
	if(n > 4)
		printf("Glupenky Pierre");
	
	else
		for(int i=0; i<n; i++)
			printf("%02d " ,a[i]);
}
