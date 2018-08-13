# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <string>

# define rev(x) reverse( x.begin(), x.end() )

using namespace std;

int n;
string s,s1,s2,s3;

int main (){
ios_base::sync_with_stdio(false);	
cin.tie(NULL);	
	
	cin >> s;
		
	for (int i = 0; i < (int)s.length(); i++)
	{
		s3 += s[i];
		rev (s3);
		
		s1 = s+s3;
		s2 = s1;
		
		rev(s2);
		
		if (s1==s2){
			cout << s1;
			return 0;
		}
		
		rev(s3);
		
	}
		
	return 0;
}
