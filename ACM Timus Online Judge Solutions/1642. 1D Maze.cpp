# include <iostream>
# include <math.h>
# include <cmath>
# include <vector>
# include <algorithm>

using namespace std;

int n,m,a,b;
vector < int > v;

int main ()
{
	cin>>n>>m;
	v.resize ( n );
	
	for ( int i = 0; i < n; i++ )
		cin>>v[i];
	
	v.push_back(m);
	v.push_back(0);
	
	sort ( v.begin(), v.end() );
	
	for ( int i = 0; i < (int)v.size(); i++ )
	{
		if ( v[i] == 0 )
		{
			if ( v[i+1] == m )
			{
				a+=abs(m);
				break;
			}
			
			else if ( v[i-1] == m )
			{
				a+=abs(v[i+1]*2)+abs(m);
				break;
			}
		}	
	}
	
	for ( int i = 0; i < (int)v.size(); i++ )
	{
		if ( v[i] == 0 )
		{
			if ( v[i-1] == m )
			{
				b+=abs(m);
				break;
			}
			
			else if ( v[i+1] == m )
			{
				b+=abs(v[i-1]*2)+abs(m);
				break;
			}
		}	
	}
	
	if ( a==0 || b==0 )
		cout<<"Impossible";
	else
		cout<<a<<" "<<b;

return 0;	
}
