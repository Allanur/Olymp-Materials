# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

# define se size()

using namespace std;

int n,a;				// number of line & order word
vector < string > v;	// output

int main ()
{
	cin >> n;
	
	vector < vector < string > > s ( n, vector<string>(3) );	//	words
	
	for ( int i = 0; i < n; i++ )
		for ( int h = 0; h < 3; h++ )	cin >> s[i][h];	
	
	for ( int i = 0; i < n; i++ )	sort ( s[i].begin(), s[i].end() );
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		a-=1;
		int b=v.se-1;
		bool one=0;
		
		if ( v.se==0 )	v.push_back(s[a][0]),one=1;
	
		else if ( v[b] < s[a][0] )	v.push_back(s[a][0]),one=1;
	
		else if ( v[b] < s[a][1] )	v.push_back(s[a][1]),one=1;
	
		else if ( v[b] < s[a][2] )	v.push_back(s[a][2]),one=1;
		
		if ( one==0 )	{cout << "IMPOSSIBLE";return 0;}
	}
	
	for ( int i = 0; i < n; i++ )	cout << v[i] << "\n";
		
return 0;	
}
