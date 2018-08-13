 # include <iostream>
using namespace std;
int m,n;
int sum=0;

int main()
{
 cin>>m>>n;
 	
	for(int i=0;i<n;i++)
	{
	 int h;
	cin>>h; 
	
	sum=sum+h; 
	sum=sum-m;
	 
	if(sum<0)sum=0;
	
	
	}

	 cout<<sum;
	getchar (); getchar ();
	return 0;
}
