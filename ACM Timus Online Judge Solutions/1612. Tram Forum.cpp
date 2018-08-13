# include <iostream>
# include <fstream>
# include <stdio.h>
# include <algorithm>
# include <string>
# include <cctype>

# define lh(X) (int)X.length()

using namespace std;
ifstream fin ("file.in");

int a,b,z;
bool one;
string s,s1;

int main ()
{
	while(cin >> s)
	{
		s1.clear();
		for (int i = 0; i < lh(s); i++)
			if (isalpha(s[i]))
				s1 += s[i];
				
		z = 0, one = 0;
		for (int i = 0; i < lh(s1); i+=4)
			(s1.substr(i,4)=="tram" ? z++ : one=1);	
		if (!one)	a += z;

		z = 0, one = 0;
		for (int i = 0; i < lh(s1); i+=10)
			(s1.substr(i,10)=="trolleybus" ? z++ : one=1);
		if (!one)	b += z;
	}
	
	cout << (a>b ? "Tram driver" : (b>a ? "Trolleybus driver" : "Bus driver"));
	
	return 0;
}
