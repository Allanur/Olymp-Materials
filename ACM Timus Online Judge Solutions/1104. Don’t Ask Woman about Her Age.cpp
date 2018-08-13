# include <iostream>
# include <string>
# include <algorithm>

# define lh length()

using namespace std;

string s;
int t,mx=1,sol;

int main ()
{
	
	cin >> s;
	
	for (int i = 0; i < (int)s.lh; i++)
	{
		if ( s[i]>='A' )
			mx = max (mx, s[i]-55), sol+=s[i]-55;
		else
			mx = max (mx, s[i]-48), sol+=s[i]-48;
	}
	
	for (int i = mx+1; i <= 36 ; i++)
	{
		if (sol%(i-1)==0)
		{
			cout << i;
			return 0;
		}
	}
	
	cout << "No solution.";
	
return 0;	
}
