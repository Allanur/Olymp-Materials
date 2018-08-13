# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

# define lh length()

using namespace std;

string s;
int a,b;

int main ()
{
	cin >> s;
	
	int n = s.lh;
	
	if ( n%2==0 )
		a = n/2-1, b = n/2;
	else
		a = n/2-1, b = n/2+1;
		
	while ( a >= 0 && b < n )
	{
		if ( s[a]!=s[b] )
		{
			if ( s[a]-48 > s[b]-48 )
			{
				while ( a >= 0 && b < n )
				{
					s[b++] = s[a--];
				}
			}
			else
			{
				if ( n%2==0 )
				{
					if ( n/2!=b && s[n/2-1]!='9' )
					{
						int y = (int)s[n/2-1];
						s[n/2-1] = char(y+1), s[n/2] = char(y+1);
					}
					else
					{
						for ( int h = a+1; h < b; h++ )
							s[h] = '0';
						int y = int(s[a]);
						s[a] = char(y+1);
					}
				}	
				else
				{
					if ( s[n/2]!='9' )
					{
						int y = int(s[n/2]);
						s[n/2] = char(y+1);
					}
					else
					{
						for ( int h = a+1; h < b; h++ )
							s[h] = '0';
						int y = int(s[a]);
						s[a] = char(y+1);
					}
				}
				while ( a >= 0 && b < n )
				{
					s[b++] = s[a--];
				}
			}
			break;
		}
		a--,b++;
	}
	
	cout << s;
	
return 0;	
}
