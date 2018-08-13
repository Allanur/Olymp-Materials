#include <iostream>
#include <string>
using namespace std;
int n,x,y;
char c[3];
int men[200];
int main ()
{
	cin>>n;
	int i;
	for( i=0;i<n;i++)
	{
		
	cin>>c;
	x=c[0]-96; y=c[1]-48;	
	
		if(x-2>0 && y-1>0) men[i]++;
		if(x-2>0 && y+1<9) men[i]++;
		if(x-1>0 && y+2<9) men[i]++;
		if(x+1<9 && y+2<9) men[i]++;
		if(x+2<9 && y+1<9) men[i]++;
 		if(x+2<9 && y-1>0) men[i]++;
		if(x+1<9 && y-2>0) men[i]++;
		if(x-1>0 && y-2>0) men[i]++;				
		
	}
	
	for(int h=0;h<n;h++)
	cout<<men[h]<<endl;	
 
return 0;
}
  
