# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

int n,sol;
bool vis[29],vis1[29];
bool val[29];
string s[29][9];

int main (){
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
		for (int h = 0; h < 3; h++)
			cin >> s[i][h];
	
	while (1){
		int mx = 0, pos = 0;
			
		for (int i = 0; i < n; i++){
			if (!vis1[i]){			
				int z = 0;
				fill (vis,vis+n+1, 0);
				vis[i]  = 1;
			
				for (int h = 0; h < 3; h++){
					for (int j = 0; j < n; j++){
						if ( !vis[j] && !vis1[j] ){			
							for (int k = 0; k < 3; k++){
								if (s[i][h] == s[j][k]){
									vis[j] = 1;
									z++;
									break;
								}
							}	
						}
					}
				}
			if (mx < z)
				mx = z, pos = i;
			}
						
		}
		
		if (mx==0)
			break;
		vis1[pos] = 1;
	}
	
	for (int i = 0; i < n; i++)
		if (!vis1[i])	sol++;
	
	cout << sol;
	
	return 0;
}
