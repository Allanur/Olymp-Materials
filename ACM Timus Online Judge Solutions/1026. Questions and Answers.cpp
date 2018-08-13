# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <string.h>
using namespace std;

int n,m,d;
string s;
vector < int > v,v1;

int main ()
{
	cin>>n;
	v.resize(n);
	
	for ( int i = 0; i < n; i++ )	
		cin>>v[i];
	
	sort ( v.begin(), v.end() );
	
	cin>>s;
	
	cin>>m;
	v1.resize(m);
	
	for ( int i = 0; i < m; i++ )
		cin>>v1[i];
	
		
	for ( int i = 0; i < m; i++ )	
	{
		d=v1[i];
		cout<<v[d-1]<<endl;
	}
	
return 0;	
}
