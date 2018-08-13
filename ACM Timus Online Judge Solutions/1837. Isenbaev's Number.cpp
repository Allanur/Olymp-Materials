# include <iostream>
# include <stdio.h>
# include <string>
# include <limits.h>
# include <vector>
# include <algorithm>

# define pb push_back
# define mk make_pair
# define f first
# define s second
# define INF INT_MAX

using namespace std;

int n,deg;
bool one,two=true;
string s[109][9];
vector < pair < string, int > > v;

void psh (string name){
	
	for (int i = 0; i < (int)v.size(); i++)
		if (v[i].f==name)
			return;
	if (name=="Isenbaev")
		v.pb(mk(name,0)), one = true;
	else
		v.pb(mk(name,INF));
}

int find (string x){
	
	for (int i = 0; i < (int)v.size(); i++){
		if (v[i].f == x)
			return v[i].s;
	}
	return INF;	
}

void equal (string x, int y){
	
	for (int i = 0; i < (int)v.size(); i++)
		if (x==v[i].f && y < v[i].s){
			v[i].s = y, two = true;
			return;
		}
}

int main (){
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		
		for (int h = 0; h < 3; h++){
			
			cin >> s[i][h];
			
			psh(s[i][h]);
		}
	}
	
	sort (v.begin(), v.end());
	
	if(one){
		while (two==true){
			
			two = false;
			
			for (int i = 0; i < n; i++){
	
				deg = INF;
				
				for (int h = 0; h < 3; h++)
					deg = min (deg, find(s[i][h]));					
			
				if (deg!=INF){
					for (int h = 0; h < 3; h++)
						equal(s[i][h],deg+1);
				}
			}
		}
	}
	
	for (int i = 0; i < (int)v.size(); i++)
	{
		cout << v[i].f << " ";
		if (v[i].s==INF)
			cout << "undefined";
		else
			cout << v[i].s;
		cout << "\n";
	}
	
	return 0;
}
