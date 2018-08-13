# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int n,m,a;
vector < int > v;

int main ()
{
	cin >> n >> m;
	
	v.resize(n);
	
	for ( int i = 0; i < n; i++ )
		cin >> v[i];
	for ( int i = 0; i < n; i++ )
		v.push_back(v[i]);	
	
	a=m%n;	
	
	for ( int i = a; i < a+10; i++ )
		cout << v[i];
		
return 0;	
}
