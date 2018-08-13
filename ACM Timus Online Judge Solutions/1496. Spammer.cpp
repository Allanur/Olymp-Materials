# include <iostream>
# include <string>
# include <string.h>
# include <vector>
# include <algorithm>
using namespace std;

int n,a;
vector < string > s,v,v1;

int main ()
{
	cin>>n;	
	s.resize(n+1);
	
	for ( int i = 0; i < n; i++ )
		cin>>s[i];
	
	sort ( s.begin(), s.end() );
	
	for ( int i = 0; i < n; i++ )
	{
		if ( s[i]==s[i+1] )
		{
			
				v.push_back(s[i]);
		}
	}
		v.push_back("qwe");
		
	for ( int i = 0; i < (int)v.size(); i++ )		
	{
		if ( i==(int)v.size()-1 )	
			return 0;
			
		if ( v[i]!=v[i+1] )
			cout<<v[i]<<endl;
		
	}		
	
return 0;	
}
