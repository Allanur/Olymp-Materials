# include <stdio.h>
# include <math.h>

int n1,c1;
int n2,t,c2;
int n3;
int K,m,s,all;

int main ()
{

	scanf ("%d %d" ,&n1 ,&c1);
	scanf ("%d %d %d" ,&n2 ,&t ,&c2);
	scanf ("%d" ,&n3);
	
	scanf ("%d" ,&K);
	
	for (int i = 0; i < K; i++)
	{
		scanf ("%d:%d" ,&m,&s);
		m = m*60+s;
		
		if (m>6)
			all += ceil((double)m/60);
	}
	if (all>t)
		n2 = n2+((all-t)*c2);
		
	printf("Basic:     %d\n" ,n1+(all*c1));
	printf("Combined:  %d\n" ,n2);
	printf("Unlimited: %d"   ,n3);
	
	return 0;
}
