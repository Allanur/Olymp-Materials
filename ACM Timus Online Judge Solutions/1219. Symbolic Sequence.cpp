# include <stdio.h>

# define maxn 1000000

int let;

int main ()
{	
	while(let<maxn)
	{
		for (int i = 97; i <= 122; i++)
		{
			for (int h = 97; h <= 122; h++)
			{
				for (int j = 97; j <= 122; j++)
				{
					printf ("%c" ,i);
					let++;
					if (let==maxn)
						return 0;
					printf ("%c" ,h);
					let++;
					if (let==maxn)
						return 0;
					printf ("%c" ,j);
					let++;
					if (let==maxn)
						return 0;
				}
			}
		}
	}
return 0;
}
