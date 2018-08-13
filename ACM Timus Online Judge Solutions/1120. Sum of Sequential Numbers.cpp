# include <iostream>

using namespace std;

int n;

int main ()
{
	cin>>n;
	
	for ( int p = 31624; p > 0; p--  )
	{
		if ( (n-(p*(p-1))/2)/p > 0 && (n-(p*(p-1)/2))%p==0 )				
		{
			cout<<(n-(p*(p-1))/2)/p<<" "<<p;
			return 0;
		}				
	}
	
return 0;	
}


