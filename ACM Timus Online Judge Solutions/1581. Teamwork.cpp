#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
 
using namespace std;
int main ()
{

int n,b,c=0;
cin>>n;

vector < int > a(n),d,e;


for(int i=0;i<n;i++)
cin>>a[i];

b=a[0];
for(int i=0;i<n;i++)
{
	if(b!=a[i])
	{
		d.push_back(c);
		d.push_back(b);
		c=0;
		b=a[i];
		i--;
	}
	else
	c++;
}

		d.push_back(c);
		d.push_back(b);
		cout<<d[0];
		
for(int i=1;i<d.size();i++)
cout<<' '<<d[i] ;
 getchar ();getchar ();
return 0;
}

