# include <iostream>
using namespace std;

int n,x,y;

int main ()
{
	cin>>n;
	
	for ( int i = 1; i <= n; i++ )
	{				
		if ( i%2==0 )
			x+=i;
		if ( i%2==1 )
			y+=i;			
	}
	
	if ( ( x%2==0 && y%2==1 ) || ( x%2==1 && y%2==0 ) )
		cout<<"grimy";
	else
		cout<<"black";

return 0;
}
