#include <iostream>
#include <string>

using namespace std;

int main ()

{
	int n;
	string a;
	
	getline(cin,a);
	
	n=a.length();
  
	int sum=0;	 
	
		for(int i=0;i<n;i++)
		{
			if(a[i]=='a'||a[i]=='d'||a[i]=='g'||a[i]=='j'||a[i]=='m'||a[i]=='p'||a[i]=='s'||a[i]=='v'||a[i]=='y'||a[i]=='.'||a[i]==' ')
				sum=sum+1;	
			if(a[i]=='b'||a[i]=='e'||a[i]=='h'||a[i]=='k'||a[i]=='n'||a[i]=='q'||a[i]=='t'||a[i]=='w'||a[i]=='z'|| a[i]==',')
				sum=sum+2;
			if(a[i]=='c'||a[i]=='f'||a[i]=='i'||a[i]=='l'||a[i]=='o'||a[i]=='r'||a[i]=='u'||a[i]=='x'||a[i]=='!')
				sum=sum+3;		
		}

cout<<sum;
getchar ();getchar ();
return 0;
}
