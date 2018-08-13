# include <iostream>
# include <algorithm>

using namespace std;

int n,m,x,y,mx,yu,z,sol;
int v[109];
string s[19];
string name,medal;
char c;

int main ()
{
	for (int i = 1; i <= 12; i++)
		cin >> s[i];
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		
		yu = 0;
		cin >> m;
		
		for (int h = 0; h < m; h++){
		
			cin >> name >> c >> medal;
			
			if (medal=="gold")
				x = 1, y = 4;
			else if (medal=="silver")
				x = 5, y = 8;
			else
				x = 9, y = 12;
			for (int j = x; j <= y; j++){
				if (s[j]==name){
					yu++;
					break;
				}			
			}			
		}
		
		v[z++] = yu;
		
	}
	
	sort (v,v+z);
	
	int pos = z-1;
	
	while (v[pos--] == v[z-1] && pos>=-1) sol++;
	
	cout << sol*5;
	
return 0;
}
