# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
long long n,m,a,z,d,b;
vector < long long > v,v1;

void func ( long long x )
{
	
	if ( binary_search ( v.begin(), v.end(), x ) )
		z++;
	
}

int main ()
{
	cin>>n;
	v.resize(n);
	
	for ( int i = 0; i < n; i++ )
		{cin>>b;v.push_back(b);}
	
	sort ( v.begin(), v.end());
	
	cin>>m;
	
	for ( int i = 0; i < m; i++ )	
	{
		cin>>a;
		v1.push_back(a);
	}
	
	for ( int i = 0; i < m; i++ )
	{
		d=v1[i];
		func(d); 
	}
	
	cout<<z;
	
return 0;	
}
