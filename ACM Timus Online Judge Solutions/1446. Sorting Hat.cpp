# include <iostream>
# include <string>
# include <string.h>
# include <vector>
# include <algorithm>

using namespace std;

int n;
vector < string > v;

int main ()
{
	cin>>n;
	
	v.resize(n*2+1);
	
	for ( int i = 0; i < n*2+1; i++ )
		getline (cin,v[i]);
	
	cout<<"Slytherin:\n";
	for ( int i = 0; i < n*2+1; i+=2 )
		if ( v[i]=="Slytherin" )
			cout<<v[i-1]<<"\n";
			
	cout<<"\n";
	cout<<"Hufflepuff:\n";
	for ( int i = 0; i < n*2+1; i+=2 )
		if ( v[i]=="Hufflepuff" )
			cout<<v[i-1]<<"\n";
			
	cout<<"\n";
	cout<<"Gryffindor:\n";
	for ( int i = 0; i < n*2+1; i+=2 )
		if ( v[i]=="Gryffindor" )
			cout<<v[i-1]<<"\n";
			
	cout<<"\n";
	cout<<"Ravenclaw:\n";
	for ( int i = 0; i < n*2+1; i+=2 )
		if ( v[i]=="Ravenclaw" )
			cout<<v[i-1]<<"\n";
		
return 0;	
}
