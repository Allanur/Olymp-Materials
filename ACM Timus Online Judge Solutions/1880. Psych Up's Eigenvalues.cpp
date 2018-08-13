#include <iostream>
 
using namespace std;
 
int a,b,c,sum;

int x[5000],y[5000],z[5000];
 
int main ()
{
	cin>>a;
	for(int i=0;i<a;i++)
	cin>>x[i];
	cin>>b;
	for(int i=0;i<b;i++)
	cin>>y[i];
	cin>>c;
	for(int i=0;i<c;i++)
	cin>>z[i];
	
	a=a-1;
	b=b-1;
	c=c-1;
	
	while(1)
	{
		if(a<0 || b<0 || c<0)
		break;
		
		if(x[a]==y[b] && x[a]==z[c])
		{
			sum++;
			a--;
			b--;
			c--;
			
			continue;
		}
		
		if(x[a]>=y[b] && x[a]>=z[c])
		{a--; continue;}
		
		if(y[b]>=x[a] && y[b]>=z[c])		
		{b--; continue;}
		
		if(z[c]>=x[a] && z[c]>=y[b])
		{c--; continue;}
	}	
	cout<<sum;		
 
	getchar (); getchar ();
	return 0;
}
