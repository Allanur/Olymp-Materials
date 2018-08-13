#include <iostream>

using namespace std;
double n,m;
double res;
int main ()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		res+=m;
	}
	cout.precision(6);
	cout<<fixed<<res/n;
	
	
 
return 0;
}
