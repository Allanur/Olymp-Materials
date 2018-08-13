 #include <iostream>
 
 using namespace std;
 
 int main ()
 
 {
		int n,m=0,h=0;
		cin>>n;
		if(n>0 )
		{
		for(int i=1;i<=n;i++)
		{
			m=m+i;
		}
		cout<<m;
		}

if(n<0)
{
for(int i=1;i>=n;i--)	
	{
	h=h+i;	
	}
cout<<h;
}	



getchar (); getchar ();
return 0;		
 }
