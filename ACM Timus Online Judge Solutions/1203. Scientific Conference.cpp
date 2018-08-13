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
# define  maxn 		  (int)1e5+9
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


int n,a,b;
int dp[maxn];
vip v;

int bs (int x, int till){
	
	int head = 0, tail = till, mid = 0;
	
	while (head<=tail){
		mid = (head+tail)/2;
		if (v[mid].f<x && v[mid+1].f>=x)
			return mid;
		else if (v[mid].f < x)
			head = mid+1;
		else
			tail = mid-1;		
	}
	return -1;
}

int main (){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.pb ( mp(b,a) );
	}
	
	svi(v);
	
	dp[0] = 1;
	for (int i = 1; i < n; i++)
		dp[i] = max( dp[i]+1, max (dp[i-1], dp[ bs(v[i].s, i-1) ]+1) );
		
	cout << dp[n-1];
		
	//printf ("%lf" ,(clock()-start)/1000.0);
	//cerr << (lf)(clock()-start)/1000.0;
return 0;
}

