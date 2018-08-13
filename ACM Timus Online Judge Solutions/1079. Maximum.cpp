# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

vector < int > v,b(99999);
int n,k;

void func ( int x )
{
		k=0;
		for ( int i = 0; i <= x; i++ )
			if ( k < b[i] )
				k=b[i];
				
	cout<<k<<endl;	
}	

int main ()
{
	b[0]=0;
	b[1]=1;

	while (1)
	{
		cin>>n;
		if ( n==0 )
			break;			

		else
		v.push_back (n);
	}
	
	for ( int i = 2; i <= 99999; i++ )
	{
		if ( i%2==0 )
			b[i]=b[i/2];
			
		else if ( i%2==1 )	
			b[i]=b[i/2]+b[i/2+1];
	}
	
	for ( int i = 0; i < (int)v.size(); i++ )	
		func ( v[i] );

return 0;	
}
