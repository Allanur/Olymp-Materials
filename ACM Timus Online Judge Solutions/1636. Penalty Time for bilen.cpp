#include <iostream>
#include <vector>
using namespace std;
int n,m,a,res;
vector < int > ab;
int main ()
{
	cin>>n>>m;
	for(int i=0;i<10;i++)
	{
		cin>>a;
		res=a*20;
	    ab.push_back(res);
	}
	
	for(int i=0;i<10;i++)
	n=ab[i]+n;
				   
	 
	if(n<=m)
	cout<<"No chance.";
	
	else
	cout<<"Dirty debug :(";
	

getchar (); getchar ();
return 0;
}
