# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int n,a,b;
vector < vector < int > > v;

int main ()
{
	cin>>n;
	v.resize(n);
	
	for ( int i = 0; i < n; i++ )
		v[i].resize(n);
		
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j <n; j++ )		
			cin>>v[i][j];
	
	cout<<v[0][0];	
		
	for ( int i = 1; i < n; i++ )
	{
		a=i,b=0;
				
		while(a > -1 && b < n)
		{
			cout<<" "<<v[a][b];		
			a--,b++;
		}
	}
	
	for ( int i = 1; i < n; i++ )
	{
		a=n-1,b=i;
				
		while(b < n)
		{
			cout<<" "<<v[a][b];		
			a--,b++;
		}
	}
	
return 0;	
}
