# include <iostream>
# include <string>
# include <algorithm>

# define lh(x) (int)x.length()

using namespace std;

int t[9][9], mn = 66666;
string sol;
string s[]={"1 2 3 4 5",
			"1 4 3 2 5",
			"1 3 2 4 5",
			"1 3 4 2 5"};
int main ()
{
	for (int i = 1; i <= 5; i++)
		for (int h = 1; h <= 5; h++)
			cin >> t[i][h];
	
	for (int i = 0; i < 4; i++)
	{
		int sum = 0, a = 1;
		for (int h = 0; h < lh(s[i]); h+=2)
		{
			sum += t[a][s[i][h]-'0'];
			a = s[i][h]-'0';
		}
		
		if (mn > sum)
			mn = sum, sol = s[i];
	}
	
	cout << mn << "\n" << sol;
	
	return 0;
}
