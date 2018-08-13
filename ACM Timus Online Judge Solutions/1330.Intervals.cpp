# include <iostream>
# include <vector>
using namespace std;

int n,a,b;
vector < int > t(10009);

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	
	for(int h=1; h<=n; h++)
	{
		cin>>t[h];
		t[h]+=t[h-1];
	}
	
	cin>>n;
	
	for(int  h=0; h<n; h++)
	{
		cin>>a>>b;
		cout<<t[b]-t[a-1]<<endl;
	}
	
return 0;	
}

