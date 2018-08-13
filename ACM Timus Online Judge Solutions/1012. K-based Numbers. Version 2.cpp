# include <stdio.h>
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

# define lh length()

using namespace std;

int n,k;
string sol,s2;
string dp[1999][1999];

void func ( string s, string s1)
{
	s2.clear();
	int sz=abs((int)s1.lh-(int)s.lh), x = 0;
	
	if (s.lh < s1.lh)
	{
		reverse (s.begin(),s.end());
		for (int i = 0; i < sz; i++)	s.push_back(0+48);							
		reverse (s.begin(),s.end());		
	}
	else
	{
		reverse (s1.begin(),s1.end());
		for (int i = 0; i < sz; i++)	s1.push_back(0+48);				
		reverse (s1.begin(),s1.end());				
	}
	
	sz=s.lh;
	for ( int i = sz-1; i >= 0; i-- )			
	{
		int sum=(s[i]-48)+(s1[i]-48)+x;	
		if (sum>=10 && i-1>=0)	{ s2+=(sum%10)+48; s[i-1]++; }
		else if(sum>=10 && i-1<0)	{s2.push_back((sum%10)+48),s2.push_back('1');}
		else s2.push_back(sum+48);
	}
	reverse(s2.begin(), s2.end());
}

int main ()
{
	scanf ( "%d%d" ,&n ,&k );
	
	for ( int i = 0; i < k; i++ )	dp[0][i] = 1+48;
	
	for ( int i = 1; i < n; i++ )
		for ( int h = 0; h < k; h++ )
			for ( int j = 0; j < k; j++ )
				if ( h || j )
				{
					func ( dp[i][h], dp[i-1][j]);
					dp[i][h] = s2;
				}
	
	for ( int i = 1; i < 10; i++ )
	{
		func ( sol, dp[n-1][i] );
		sol = s2;
	}
	
	cout << sol << " ";
	
return 0;	
}
