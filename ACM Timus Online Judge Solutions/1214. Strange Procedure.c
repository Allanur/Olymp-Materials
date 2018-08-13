# include <stdio.h>

int x, y, tmp;

int main ()
{
	scanf ("%d %d" ,&x ,&y);
	
	if (x>0 && y>0 && (x+y)%2)
		tmp = x, x = y, y = tmp;
	
	printf ("%d %d" ,x ,y);	
		
	return 0;
}
