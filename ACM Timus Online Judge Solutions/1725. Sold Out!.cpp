# include <iostream>
# include <cmath>
# include <math.h>
using namespace std;

int n,m;

int main ()
{
	cin>>n>>m;
	
	if ( n==2 )
		cout<<"0";
	else if ( n-m-2 > m-3 )	
		cout<<n-m-2;
	else
		cout<<m-3;
	
return 0;	
}
