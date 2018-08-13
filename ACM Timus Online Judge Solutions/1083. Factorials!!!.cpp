# include <iostream>
# include <algorithm>
# include <string>
# include <string.h>
using namespace std;
long long n,a,b,res=1;
string s;
int main ()
{
	cin>>n>>s;
	a=s.length();
	b=n%a;
	for ( int i = 1; i <= n; i++ )
		if ( i%a==b )
			res*=i;
	
	cout<<res;
	
return 0;	
}
