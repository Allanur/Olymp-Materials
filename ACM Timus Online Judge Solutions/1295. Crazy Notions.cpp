# include <stdio.h>

int n;

int main ()
{
	scanf("%d" ,&n);
	
	if ((n%4==1 && n%5==0) || n%4==3)
		printf ("2");
	else if (n%4==0)
		printf ("0");
	else
		printf ("1");
	
return 0;	
}
