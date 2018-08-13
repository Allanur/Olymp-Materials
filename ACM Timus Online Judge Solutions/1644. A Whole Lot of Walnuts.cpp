# include <iostream>
# include <string>

using namespace std;

int n,wal,sat=10,hun;
string s;

int main ()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> wal >> s;
		if (s=="hungry")
			hun = max (hun,wal);
		else
			sat = min (sat,wal);
	}
	
	if (sat>hun)
		cout << sat;
	else
		cout << "Inconsistent";
	
return 0;	
}
