# include <iostream>
# include <string>
# include <string.h>
# include <vector>
# include <algorithm>
using namespace std;

string s;
vector < char > v;

int main ()
{
	cin>>s;
	v.push_back(s[0]);
	
	for ( int i = 1; i < (int)s.length(); i++ )
	{
		if ( v.size()==0 )
			v.push_back(s[i]);
			
		else if ( v[((int)v.size()-1)]==s[i] )
			v.pop_back();
		
		else
			v.push_back(s[i]);
		
	}	

	for ( int i = 0; i < (int)v.size(); i++ )
		cout<<v[i];
	
return 0;	
}
