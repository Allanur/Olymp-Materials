# include <iostream>
# include <algorithm>
# include <limits.h>

# define INF INT_MAX

using namespace std;

int t,n,a,b;
int sol = INF;
int v[109][109];
char c;

int main (){
	
	for (int i = 0; i <= 40; i++)
		for (int h = 0; h <= 40; h++)
			v[i][h] = INF;

	cin >> t;
	
	for (int i = 1; i <= t; i++){
		cin >> n;
		
		for (int h = 1; h <= n; h++){
			
			while (cin>>a){
				if (a==0)	break;
				cin >> b;
				
				if (i==1) v[i][h] = b;
				else v[i][h] = min (v[i][h], v[i-1][a]+b);
				
				if (i==t) sol = min(sol,v[i][h]);
			}			
		}
		
		if (i!=t) cin >> c;
	}
	
	cout << sol;
	
return 0;	
}
