# include <iostream>
# include <vector>
# include <algorithm>
# include <math.h>
# include <cmath>
using namespace std;

bool prime ( int n )
{
	int yes=(int)sqrt(n);
	
	for ( int i = 2; i <= yes; i++ )
		if ( n%i==0 )
			return 0;
			
			return 1;		
}

int n,a;
double sat;
vector < int > v,v1(15000);
int main ()
{
	cin>>n;	

	for ( int i = 2; i <= 15000; i++ )
		if ( prime(i) == 1 )
			v.push_back(i);
			
	for ( int i = 0; i < n; i++ )	
		cin>>v1[i];
				
	for ( int i = 0; i < n; i++ )
		cout<<v[v1[i]-1]<<"\n";
	
return 0;			
}
