#include <iostream>
using namespace std;
int n,m;
int q,w,e,r,t,y,u,i,o,p;
int a,s,d,f,g,h,j,k,l,z;
int res,res1;
int main ()
{
	cin>>n>>m;	 
	cin>>q>>w>>e>>r>>t>>y>>u>>i>>o>>p;
		
	a=q*20;		s=w*20; 
	d=e*20;		f=r*20;	 
	g=t*20;		h=y*20;
	j=u*20;		k=i*20;
	l=o*20;		z=p*20;
	 
	 
	 res=a+d+g+j+l+s+f+h+k+z;
	 res1=n+res;
	
	if(res1<=m)
	cout<<"No chance.";
	 
	else
	cout<<"Dirty debug :(";
 
return 0;
}
