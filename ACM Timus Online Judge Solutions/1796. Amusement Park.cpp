# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

int all,x,y=5000,z;
int R[]={10,50,100,500,1000,5000};
int t[6660009];

int main ()
{
	for (int i = 0; i < 6; i++)
	{
		cin >> x;
		if (x)	y = min (y,R[i]);
		all += x*R[i];
	}
	cin >> x;
	
	for (int i = 1; i <= all/x; i++)
		if (all - (i*x) < y)
			t[z++] = i;
	
	cout << z << "\n";
	for (int i = 0; i < z; i++)
		cout << t[i] << " ";
	
	return 0;
}
