# include <iostream>
# include <string>
# include <string.h>
# include <vector>
# include <algorithm>
using namespace std;

string s;
string harp="abcdefghijklmnopqrstuvwxyz";
vector < int > v,v1;

int main ()
{
	cin>>s;
	
	for ( int i = 0; i < (int)s.length(); i++ )
		for ( int j = 0; j < (int)harp.length(); j++ )
			if ( s[i]==harp[j] )
				v.push_back(j);
	
	if ( v[0]+26<=30 )	
		v[0]=v[0]+26;			
				
	for ( int i = 1; i < (int)v.size(); i++ )
		v[i]=v[i]+26;
	
	for ( int i = (int)v.size(); i > 0; i-- )
	{
		v[i]-=v[i-1];
		if ( v[i] < 0 )
			v[i]+=26;		
	}	
		v[0]-=5;
	for ( int i = 0; i < (int)v.size(); i++ )	
	{
		if ( v[i] >= 26 )
			while ( v[i]>=26 )
				v[i]-=26;		
		cout<<harp[v[i]];
	}	
return 0;	
}
