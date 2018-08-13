#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MOD 1000000007

const int MAXN = 100009;

using namespace std;
typedef long long ll;

int n,m,a,b;
ll pw[MAXN];
char s[MAXN];

struct Fenwick {
	ll tree[MAXN];
	
	void upd(int x, int val) {
		for (int i=x; i<=n;  i+=i&-i)
			tree[i] += val;
	}
	
	ll _tap(int x) {
		ll ret = 0;
		for (int i=x; i>0; i-=i&-i)
			ret += tree[i];
		return ret;
	}
	
	int tap(int x, int y) {
		return (_tap(y) - _tap(x-1) + MOD) % MOD;
	}
} T1, T2;

int main()
{
	scanf("%s %d" ,s+1 ,&m);
	n = strlen(s+1);
	
	pw[0] = 1LL;	
	for (int i=1; i<=n; i++)
	{
		ll val = (s[i]-'a') * 1LL * pw[i-1];
		val %= MOD;
		T1.upd(i, val);
		
		val = (s[n-i+1]-'a') * 1LL * pw[i-1];
		val %= MOD;
		T2.upd(i, val);
		
		pw[i] = (pw[i-1] * 37) % MOD;
	}
	
	while(m--)
	{
		scanf("%s" ,s);
		
		if (s[0]=='c')
		{
			scanf("%d %c" ,&a ,&s[0]);
			
			ll val = (s[0]-'a') * 1LL * pw[a-1];
			val %= MOD;
			ll q = T1.tap(a, a);
			T1.upd(a, (val-q+MOD) % MOD);
			
			a = n-a+1;
			val = (s[0]-'a') * 1LL * pw[a-1];
			val %= MOD;
			q = T2.tap(a, a);
			T2.upd(a, (val-q+MOD) % MOD);
			
			continue;
		}
		
		scanf("%d %d" ,&a ,&b);
		
		int na=n-b+1, nb=n-a+1;
		ll val1 = T1.tap(a,b);
		ll val2 = T2.tap(na,nb);
		
		if (a<=na)
			val1 = (val1 * pw[na-a]) % MOD;
		else
			val2 = (val2 * pw[a-na]) % MOD;
		
		printf("%s\n" ,(val1==val2 ? "Yes" : "No"));
	}
}
