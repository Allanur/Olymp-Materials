# include <iostream>
# include <stdio.h>
# include <fstream>
# include <limits.h>
# include <math.h>
# include <cmath>
# include <time.h>
# include <stdlib.h>
# include <algorithm>
# include <string>
# include <string.h>
# include <iomanip>
# include <map>
# include <queue>
# include <stack>
# include <vector>
# include <cctype>


# define  INF 		  INT_MAX
# define  maxn 		  (int)1e6+9
# define  lh(x)		  (int)x.length()
# define  sz(x) 	  (int)x.size()
# define  rev(x) 	  reverse (x.begin(), x.end());
# define  svi(x)	  sort (x.begin(), x.end());
# define  svd(x) 	  sort (x.rbegin(), x.rend());
# define  sai(x,till) sort (x,x+till);
# define  pb		  push_back
# define  ppb		  pop_back
# define  mp		  make_pair
# define  f			  first
# define  s			  second



using namespace std;
time_t start = clock();
typedef long long ll;
typedef double 	dl;
typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pair < int,int > > vip;


int n,ans;
int v[109];


int main (){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sai(v,n);
	
	for (int i = 0; i < (n+1)/2; i++)
		ans += (v[i]+1)/2;
	
	cout << ans;
			
	//printf ("%lf" ,(clock()-start)/1000.0);
	//cerr << (lf)(clock()-start)/1000.0;
return 0;
}
