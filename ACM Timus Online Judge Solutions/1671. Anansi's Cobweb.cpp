# include <iostream>
# include <stdio.h>
# include <algorithm>

# define maxn (int)1e5+9

using namespace std;

struct ooo {
	int a,b;
} v[maxn];

int n,m,Q,z;
int fa[maxn],sz[maxn],q[maxn];
bool vis[maxn];

int root (int x){
	if (fa[x]==x)
		return x;
	return fa[x] = root(fa[x]);
}

void uni_on (int x, int y){
	int a = root(x), b = root(y);

	if (sz[a] < sz[b])
		swap(a,b);

	if (fa[b]==b && fa[a]!=fa[b])	z--;
	
	fa[b] = a, sz[a] += sz[b];	
}

int main (){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	
	cin >> n >> m;
	z = n;
	
	for (int i = 1; i <= n ; i++)	
		fa[i] = i, sz[i] = 1;
	
	for (int i = 1; i <= m; i++)
		cin >> v[i].a >> v[i].b;
	
	cin >> Q;
	
	for (int i = 0; i < Q; i++){
		cin >> q[i];
		vis[q[i]] = true;
	}
	
	for (int i = 1; i <= m; i++){
		if (!vis[i])
			uni_on(v[i].a, v[i].b);
	}
	
	q[Q] = z;
	for (int i = Q-1; i >= 1; i--){
		uni_on ( v[q[i]].a , v[q[i]].b );
		q[i] = z;
	}
	
	for (int i = 1; i <= Q; i++)
		cout << q[i] << " ";
		
	return 0;
}
