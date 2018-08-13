# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

vector < long long > oka(3),v;
long long a,q;

int main ()
{
	for ( int i = 0; i < 3; i++ )
		cin>>oka[i];
		
	while (1)
	{
		sort ( oka.begin(), oka.end() );
		reverse ( oka.begin(), oka.end() );
			a=0;
			
		for ( int i = 0; i < (int)oka.size(); i++ )
			for ( int j = i+1; j < (int)oka.size(); j++ )
			{	
				if ( a==0 )
					a = oka[i]-oka[j];
				else
					a = min ( a, oka[i]-oka[j] );
			}
			
		if ( a!=0 )
		{
			q++;
			oka.push_back ( a );	
		}
		
		else
			break;
	}
				
	cout<<q+1;
	
return 0;	
}
