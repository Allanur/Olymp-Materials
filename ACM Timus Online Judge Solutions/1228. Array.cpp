# include <iostream>
# include <stdio.h>

using namespace std;

int n, s, d;

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

	cin >> n >> s;
	
	for (int i = 0; i < n; i++)
	{
		cin >> d;
		cout << s/d-1 << " ";
		s = d;
	}
	
	return 0;
}
