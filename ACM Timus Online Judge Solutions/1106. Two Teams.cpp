# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int n,x;
bool t1[109],t2[109];
int t[109],z;
vector < vector < int > > v;

int main ()
{
	cin >> n;
	v.resize(n+1);
	
	for (int i = 1; i <= n; i++)
	{
		while (cin >> x)
		{
			if (x==0)
				break;
			v[i].push_back(x);
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!t1[i] && !t2[i])
		{
			bool one = 0;
			
			for (int h = 0; h < v[i].size(); h++)
			{	
				if (t1[v[i][h]])
				{
					t2[i] = 1, one = 1;
					break; 
				}
				if (t2[v[i][h]])
				{
					t1[i] = 1, one = 1;
					break;
				}
			}
			if (!one)
				t1[i] = 1;
		}
		
		for (int h = 0; h < v[i].size(); h++)
			if (!t1[v[i][h]] && !t2[v[i][h]])
				( t1[i] ? t2[v[i][h]] = 1 : t1[v[i][h]] = 1 );
	}
	for (int i = 1; i <= n; i++)
		if (t1[i])
			t[z++] = i;
	cout << z << "\n";
	for (int i = 0; i < z; i++)
		cout << t[i] << " ";
	
return 0;	
}

