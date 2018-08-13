#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define ff first
#define ss second
#define sz(c) (int)c.size()
#define ln(c) (int)c.length()
#define all(c) (c).begin(), (c).end()

template <typename A, typename B> inline void umin(A &x, B y) {if(x>y) x=y;}
template <typename A, typename B> inline void umax(A &x, B y) {if(x<y) x=y;}

#define INF 1000000000
#define MOD 1000000007

const int MAXN = 200005;

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int a, b, c;

int main()
{
	cin >> a >> b >> c;
	
	cout << min(a-b*c, a-b-c);
}
