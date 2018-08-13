# include <stdio.h>
# include <vector>
# include <algorithm>

using namespace std;

int n,a,b;
vector < vector < int > > v(101);

int main ()
{
	scanf ( "%d" ,&n );
	
	for ( int i = 0; i < n; i++ )
	{
		scanf ( "%d %d" ,&a ,&b );
		v[b].push_back(a);
	}
	
	for ( int i = 100; i >= 0; i-- )
	{
		for ( int h = 0; h < (int)v[i].size(); h++ )
			printf ( "%d %d\n" ,v[i][h] ,i );		
	}
	
return 0;	
}

