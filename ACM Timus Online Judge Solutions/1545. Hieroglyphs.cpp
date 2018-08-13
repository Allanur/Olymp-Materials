# include <iostream>
# include <algorithm>
# include <string>
# include <string.h>
using namespace std;

int n;

string s[10000];
char h;

int main ()
{
	cin>>n;
	
	for ( int i = 0; i < n; i++ )
		cin>>s[i];
	
	cin>>h;
	
	for ( int i = 0; i < n; i++ )
		if ( h==s[i][0] )
			cout<<s[i]<<endl;
	
return 0;	
}
