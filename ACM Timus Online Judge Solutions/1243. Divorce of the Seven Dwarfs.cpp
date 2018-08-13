# include <iostream>
# include <string>
# include <algorithm>

# define lh length()

using namespace std;
typedef long long ll;

string s;
ll x,sum;

ll bigmod ( ll b, ll p, ll m )
{
	if (p==0)	return 1;	
	else if (p%2==0)	{ ll x=bigmod(b,p/2,m); return (x*x)%m;}
	else 	return ((b%m)*(bigmod(b,p-1,m)))%m;
}

int main ()
{
	cin >> s;
	
	int sz=(int)s.lh-1;
	
	for ( int i = 0; i < (int)s.lh; i++ )
	{	
		x=(s[i]-48);		
		sum+=(bigmod(10,sz,7)*(x%7))%7;
		sz--;
	}

	cout << sum%7;

return 0;	
}
