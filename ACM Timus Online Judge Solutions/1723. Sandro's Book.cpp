# include <iostream>
# include <string>
# include <algorithm>

# define lh length()

using namespace std;

string s;
int mx,pos,v[109];

int main ()
{
	cin >> s;
	
	for ( int i = 0; i < s.lh; i++ )
		v[(int)s[i]-96]++;
	
	for ( int i = 1; i <= 26; i++ )
		if ( mx < v[i] )
			mx = v[i], pos = i;
	
	cout << (char)(pos+96);
	
return 0;
}
// abababa
