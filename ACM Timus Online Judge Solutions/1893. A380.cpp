# include <iostream>

using namespace std;

int san;
char harp;

int main ()
{
	cin>>san>>harp;
	
	if ( san<=2 )
	{
		if ( harp=='A' || harp=='D' )
			cout<<"window";
		else
			cout<<"aisle";
		
	}
	else if ( san>2 && san<=20 )
	{
		if ( harp=='A' || harp=='F' )
			cout<<"window";
		else
			cout<<"aisle";
	}
	
	else if ( san>20 && san<=65  )
	{
		if ( harp=='A' || harp=='K' )
			cout<<"window";
		else if ( harp=='B' || harp=='E' || harp=='F' || harp=='J' )	
			cout<<"neither";
		else
			cout<<"aisle";
	}
	
return 0;
}
