# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

# define lh length()
# define se size()

using namespace std;

string s;					// scanf
vector < char > v,v1,r;		// check & output

int main ()
{
	cin >> s;
	
	for ( int i = 0; i < (int)s.lh; i++ )
	{		
		v.clear();
		
		for ( int h = i; h < (int)s.lh; h++ )	v.push_back(s[h]);
		
		while ( (int)v.se!=0 && r.se<v.se )
		{
			v1=v;
			reverse (v1.begin(), v1.end());
			
			if ( v==v1 && v.se > r.se )		r=v;	
						
			v.pop_back();
		}	
	}
	
	for ( int h = 0; h < (int)r.se; h++ )	cout << r[h];
	
return 0;	
}
