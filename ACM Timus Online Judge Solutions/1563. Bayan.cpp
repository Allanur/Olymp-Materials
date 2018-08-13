# include <iostream>
# include <stdio.h>
# include <vector>
# include <algorithm>
# include <string>
# include <string.h>
using namespace std;

int n,z=1;
vector < vector < char > > v,s;
char c;

int main ()
{
	scanf("%d\n" ,&n);
	v.resize(n);
	
	for ( int i = 0; i < n; i++ ) 
	{
		while (1)
		{			
			scanf ("%c" ,&c);
			if (c==10)
			break;
			
			v[i].push_back(c);
		}  
	}
	
	sort ( v.begin(), v.end() );
	
	for ( int i = 0; i < n-1; i++ )
		if ( v[i]!=v[i+1] )
			z++;
	
	cout<<n-z;
	
return 0;	
}
