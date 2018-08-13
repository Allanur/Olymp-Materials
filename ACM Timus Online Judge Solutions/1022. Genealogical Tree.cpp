# include <stdio.h>
# include <vector>
# include <algorithm>

using namespace std;

int n,x,z;
bool vis[109];
vector < vector <int> > v;

int main ()
{
	scanf("%d" ,&n);
	v.resize(n+1);
	
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		while (x)
		{
			v[i].push_back(x);			
			scanf("%d",&x);
		}
	}
	while (z<n)
	{
		for (int j=1; j<=n; j++)
		{
			if(!vis[j])
			{
				bool one = 0;
				for (int i=1; i<=n; i++)
					if (!vis[i])
						for (int h=0; h<v[i].size(); h++)
							if (v[i][h]==j)
								one = 1;				
				if (!one)
				{
					printf ("%d " ,j);
					vis[j] = 1,z++;
				}
			}
		}
	}
return 0;	
}
