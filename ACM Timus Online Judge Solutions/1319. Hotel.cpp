# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int n;
vector < vector < int > > v;

int main ()
{
	cin>>n;
	
	v.resize(n);
	
	for ( int i = 0; i < n; i++ )
		v[i].resize(n);
	
	v[0][0]=1;
	
	int i = 2, h = 0, j1 = 0, h1 = 0, j = 0;
	
	while ( i<=(n*n)-1 )
	{
		if ( j < n-1 )
		{
			j++,j1=j,h1=h;
			while ( j1 >= 0 )
			{
				v[h1][j1]=i;
				i++;
				h1++;
				j1--;
			}	
		}
		
		else
		{
			h++, h1 = h, j1 = j;
			
			while ( h1<=n-1 )
			{
				v[h1][j1]=i;
				i++;
				h1++;
				j1--;				
			}			
		}				
	}
	
	v[n-1][n-1] = n*n;
	
	for ( int i = 0; i < n; i++ )	
		reverse ( v[i].begin(), v[i].end() );
	

	for ( int i = 0; i < n; i++ ) 	
	{
		for ( int h = 0; h < n; h++ )
		{
			cout<<v[i][h]<<" ";
		}	
		cout<<endl;
	}
	
return 0;	
}
