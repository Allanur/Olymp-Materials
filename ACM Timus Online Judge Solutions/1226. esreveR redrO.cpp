# include <stdio.h>

//FILE *fin = fopen("input.txt", "r");

char c, s[300];
int x;

int main ()
{
	
	//while ( fscanf(fin,"%c" ,&c)!=EOF )
	
	while ( scanf ( "%c" ,&c) != EOF )
	{	
		if ( (c>='a' && c<='z') || ( c>='A' && c<='Z' ) )
			s[x++] = c;
	
		else
		{
			for ( int i = x-1; i >= 0; i-- )
				printf ( "%c" ,s[i] );
			
			printf ( "%c" ,c );
			x = 0;
		}
	}
	
	for ( int i = x-1; i >= 0; i-- )
		printf ( "%c" ,s[i] );
	
return 0;	
}
