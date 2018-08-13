# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
# include <math.h>
using namespace std;

vector < int > v(0),v1(1);
int n,m,a,b,d,f;

int func ( int x, int y, int z )
{
	
	if ( abs(x-y) < 2  )
	{
		if ( v1[x]==z )	
			return 1;
		if ( v1[y]==z )
			return 1;
		
		return -1;	
	}		
	
	if ( v1[(x+y)/2] > z )
	return func( (x+y)/2,y,z );
		return func( x,(x+y)/2,z );
		
	
}

int main ()
{
	cin>>n;
	
	for ( int i = 0; i < n; i++ )
	{
		
		cin>>a;
		v.push_back(a);
		
	}
	
	cin>>m;
	
	for ( int i = 0; i < m; i++ )
	{
		cin>>b;
		v1.push_back(b);
	}
	
	for ( int i = 0; i < n; i++ )
	{
		d=10000-v[i];
		
		if(func(1,m,d)!=-1)
		{
			cout<<"YES";
			return 0;
		}
	}
	
	cout<<"NO";
	
return 0;	
}
