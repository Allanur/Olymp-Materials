# include <iostream>
# include <stdio.h>
# include <cctype>
# include <string>
# include <algorithm>

using namespace std;

string s;
bool one = 1;

int main ()
{
	while ( !cin.eof() )
	{
		getline ( cin, s );		
		for ( int i = 0; i < s.length(); i++ )
		{
			if ( one && isupper(s[i]) )
				one = 0;
			
			else if ( s[i]=='?' || s[i]=='!' || s[i]=='.' )
				one = 1;
		
			else
				s[i] = tolower(s[i]);
			printf ( "%c" ,s[i] );
		}
		printf ( "\n" );
	}

return 0;	
}
