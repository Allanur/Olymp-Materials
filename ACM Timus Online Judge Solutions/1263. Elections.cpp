#include <iostream>
#include <vector>
using namespace std;

double n,m,a;
 
int main ()
{
	cin>>n>>m;
	vector < double >  ab(n);
	for(int i=0;i<n;i++)
	ab[i]=0;
	
	for(int j=1;j<=m;j++)
	{
	cin>>a;
	ab[a-1]++;
	
	}

	cout.precision(2);

	for(int i=0;i<n;i++)
	cout<<fixed<<100/m*ab[i]<<"%\n";
 
	
getchar ();	getchar ();
return 0;
}
