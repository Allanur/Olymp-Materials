# include <iostream>
# include <string>
# include <string.h>
# include <vector>
# include <algorithm>
using namespace std;

char s[100][100],s1[100][100],v[100][100],v1[100][100],v2[100][100];
int a,b;

int main ()
{
	for ( int i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++ )
			cin>>s[i][j];
	for ( int i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++ )
			cin>>s1[i][j];
	
	for ( int i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++ )
			if ( s[i][j]=='X' )
				cout<<s1[i][j];
				
	for ( int i=0; i<4; i++)	
	{
		b=0;
		for ( int j=3; j>-1; j-- )	
		{
			v[a][b]=s[j][i];
			b++;	
		}
		a++;
	}
	for ( int i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++ )
			if ( v[i][j]=='X' )
				cout<<s1[i][j];
	a=0,b=0;
	for ( int i=3; i >= 0; i-- )
	{
		b=0;
		for ( int j=3; j>-1; j-- )
		{
			v1[a][b]=s[i][j];	
			b++;
		}	
		a++;
	}	

	for ( int i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++ )
			if ( v1[i][j]=='X' )
				cout<<s1[i][j];
	a=0,b=0;
	for ( int i=3; i >= 0; i-- )
	{
		b=0;
		for ( int j = 0; j < 4; j++ )
		{
			v2[a][b]=s[j][i];	
			b++;
		}	
		a++;
	}	
	for ( int i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++ )
			if ( v2[i][j]=='X' )
				cout<<s1[i][j];			

return 0;	
}
