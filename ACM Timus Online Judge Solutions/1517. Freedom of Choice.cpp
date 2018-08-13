#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 200009;

struct SArray {
	int ff, ss, pos;
	bool operator < (SArray tmp) const{
		if (ff == tmp.ff)
			return ss < tmp.ss;
		return ff < tmp.ff;
	}
};

int lcp[MAXN];
SArray L[MAXN];
int sa[19][MAXN];
int n, N, sol, p;
char s[MAXN], _tmp[MAXN/2];

void suffix_array()
{
	for (int i=0; i<N; i++)
		sa[0][i] = s[i] - 'A';
	
	for (int i=1,j=1; i<N; i*=2,j++)
	{
		for (int h=0; h<N; h++)
		{
			L[h].ff = sa[j-1][h];
			L[h].ss = h+i < N ? sa[j-1][h+i] : -1;
			L[h].pos = h;
		}
		
		sort(L, L+N);
		
		for (int h=1,k=0; h<N; h++)
		{
			if (L[h-1].ff!=L[h].ff || L[h-1].ss!=L[h].ss)
				k++;
			
			sa[j][L[h].pos] = k;
		}
	}	
}

void build_lcp()
{
	int len = log2(N), a, b, ret;
	
	for (int i=1; i<N; i++)
	{
		a = L[i-1].pos, b = L[i].pos, ret = 0;
		
		for (int j=len; j>=0; j--)
			if (ret+(1<<j)<N && a<N && b<N && sa[j][a] == sa[j][b])
				a += (1<<j), b += (1<<j), ret += (1<<j);
		
		lcp[i] = ret;
	}
}

int main()
{
	scanf("%d %s %s" ,&n ,s ,_tmp);
	N = n+n+1;
	s[n] = '#';
	for (int i=0; i<n; i++)
		s[i+n+1] = _tmp[i];
	
	suffix_array();
	build_lcp();
	
	for (int i=1; i<N; i++)
	{
		int a = L[i-1].pos, b = L[i].pos, len = lcp[i];
		if (a > b)	swap(a, b);
		if (a<n && b>n && a+len-1<n && b+len-1<N && sol < len)
			sol = len, p = a;
	}
	
	for (int i=p; i<p+sol; i++)
		printf("%c" ,s[i]);
}
