# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;
typedef short sh;

sh n;
vector < string > v;

int main ()
{
	cin >> n;	
	
	sh a = n;
	
	v.push_back("sin(");
	
	for ( sh i = 1; i <= n; i++ )
		( i%2==1 ? v.push_back("-sin(") : v.push_back("+sin("));
	
	for ( sh i = 0; i < n-1; i++ ) 
		cout << "(";

	for ( sh i = 0; i < n; i++ )
	{
		for ( sh j = 0; j <= i; j++  )
			cout << v[j] << j+1;
		
		for ( sh h = 0; h <= i; h++ )
			cout << ")";
		
		cout << "+" << a;
		
		if ( a!=1 )
			cout << ")";
		
			a--;
	}
	
return 0;	
}
