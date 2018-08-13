# include <iostream>
# include <limits.h>
# include <string>
# include <algorithm>

# define lh length()
# define INF INT_MAX
# define MAXN 4009

using namespace std;

string s, W[MAXN];
int dp[MAXN],gel[MAXN], w;
bool pal[MAXN][MAXN];

int main ()
{			
	cin >> s;
	
	int n = s.lh;
	
	s.push_back(s[n-1]);
	
	for ( int h = n-1; h >= 0; h-- )	s[h+1] = s[h];
	
	for ( int i = 1; i <= n+1; i++ )
		dp[i] = INF;
		
	for ( int i = 1; i <= n; i++ )
	{
		int a = i, b = i;
		while ( a > 0 && b <= n && s[a]==s[b] )
			pal[a--][b++] = 1;		
		
		a = i, b = i+1;
		while ( a > 0 && b <= n && s[a]==s[b] )
			pal[a--][b++] = 1;
	}
	
	for ( int i = 1; i <= n; i++ )
	{
		for ( int h = i; h <= n; h++ )
		{
			if ( pal[i][h] )
			{
				if ( dp[h] > dp[i-1]+1 )
				{
					dp[h] = dp[i-1]+1;
					gel[h] = i-1;
				}
			}
		}
	}
	
	int a = n;
	
	while(a)
	{
		W[w++] = s.substr(gel[a]+1, a-gel[a]);
		a = gel[a];
	}
		
		cout << w << "\n";
	for ( int h = w-1; h >= 0; h-- )
		cout << W[h] << " ";
	
return 0;
}
// abzzbbbzza
