# include <iostream>
# include <string>
# include <math.h>
# include <algorithm>

using namespace std;

int h, w, n, a=1, b, sz;
string s;

int main ()
{
	cin >> h >> w >> n;
	
	for ( int i = 0; i < n; i++ )
	{
		cin >> s;
		sz = (int)s.length();
		
		if ( b+sz <= w )
			b+=sz+1;
		else
			b = sz+1,a++;	
	}
	
	cout << ceil((double)a/h);
	
return 0;	
}
