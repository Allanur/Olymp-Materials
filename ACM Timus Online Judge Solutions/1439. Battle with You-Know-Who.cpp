# include <iostream>
# include <stdio.h>
# include <algorithm>

# define MAXM 100009

using namespace std;
const int con = 1000000001; ///10^9+1 ==> INF

int n, m, val;
char key;
int T[MAXM], t;

int GetPos(int x, int l, int r)
{
	if (l>=r)	return l;
	
	if (T[(l+r)/2] > x)	return GetPos(x, l, (l+r)/2);
	
	else 	return GetPos(x, (l+r)/2+1, r);
}

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

	T[t++] = con;
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		cin >> key >> val;
		
		if (key=='L')	cout << val + GetPos(val, 0, t) << "\n";
		
		else
		{
			int pos = GetPos(val, 0, t);
			for (int h = pos; h < t; h++)	T[h]--;
			for (int h = t; h > pos; h--)	T[h] = T[h-1];
			T[pos] = val;
			T[t++] = con;
		}
	}
	
	return 0;
}
