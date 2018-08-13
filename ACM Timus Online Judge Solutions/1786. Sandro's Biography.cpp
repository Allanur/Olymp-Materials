# include <iostream>
# include <string>

# define lh length()

using namespace std;

string s, a;
string sb = "Sandro";
int sol = 200*5;

int main ()
{
	cin >> s;
	
	for ( int i = 0; i < s.lh-5; i++ )
	{
		int sum = 0;
		
		a = s.substr(i, s.lh-(s.lh-6));
		
		for ( int h = 1; h < 6; h++ )
		{
			if ( a[h]!=sb[h] )
			{
				if ( a[h]==toupper(sb[h]) || a[h]==tolower(sb[h]) )		sum += 5;
				else if ( isupper(a[h]) )	sum += 10;
				else	sum += 5;
			}
		}
		if ( a[0]!=sb[0] )
		{
			if ( a[0]==toupper(sb[0]) || a[0]==tolower(sb[0]) )
				sum += 5;
			else if ( isupper(a[0]) )
				sum += 5;
			else
				sum += 10;
		}
		sol = min ( sol, sum );
	}
	
	cout << sol;
	
return 0;	
}
