# include <iostream>

using namespace std;

int n,k,a,b,x,y;

int main ()
{
	cin >> n >> k;
	
	x = k;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		x+=a,y+=b;
	}
	
	if (x >= y+(n+1)*2)
		cout << x-y-(n+1)*2;
    else 
		cout << "Big Bang!";
	
return 0;	
}
