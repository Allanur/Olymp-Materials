# include <iostream>

using namespace std;

bool v[9],x,one;

void func ()
{
	int a = (v[2]+v[3]+v[4])%2;
	int b = (v[1]+v[3]+v[4])%2;
	int c = (v[1]+v[2]+v[4])%2;
	
	if ( a==v[5] && b==v[6] && c==v[7] )
		one = 1;
}

int main ()
{
	for ( int i = 1; i <= 7; i++ )
		cin >> v[i];
	
	func();
	
	for ( int i = 1; i <= 7; i++ )
	{
		if ( !one )
		{
			if ( i==1 )
				x = v[i];
			else
				v[i-1] = x, x = v[i];
			
			if ( v[i]==1 )
				v[i] = 0;
			else
				v[i] = 1;
			func();
		}
		
		else
			break;
	}
	
	for ( int i = 1; i <= 7; i++ )
		cout << v[i] << " ";
	
return 0;	
}
