# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

struct ooo 
{
	int x,y;
} t[70009];

int n,q,l,r,x;

bool before(ooo a, ooo b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
bool bs (int l, int r, int f)
{
	int head = 0, tail = n-1, mid;
	
	while(head<=tail)
	{
		mid = (head+tail)/2;
		
		if (f==t[mid].x && f > t[mid-1].x)
		{
			while(t[mid].x==f)
			{
				if (l<=t[mid].y && t[mid].y<=r)
					return 1;
				mid++;
			}
			return 0;
		}
		else if (t[mid].x < f)
			head = mid+1;
		else
			tail = mid-1;
	}
	return 0;
}

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> t[i].x;
		t[i].y = i+1;
	}	

	sort (t,t+n,before);
	
	cin >> q;	
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r >> x;
		cout << bs(l,r,x);
	}
		
	return 0;
}
