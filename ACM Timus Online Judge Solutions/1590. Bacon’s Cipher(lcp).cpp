#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 100009;

struct mytuple {
	int orig, fhalf, shalf;
	
	bool operator < (mytuple X) const {
		
		if(fhalf == X.fhalf)
			return shalf < X.shalf;
	
		return fhalf < X.fhalf;
	}
};

int n, sol;
char s[maxn];
int lcp[maxn];
mytuple L[maxn];
int sa[20][maxn];

void suffix_array()
{
	for(int i=0; i<n; i++)
		sa[0][i] = s[i]-'a';
		
	for(int i=1,stp=1; i<n; i*=2,stp++)
	{
		for(int h=0; h<n; h++)
		{
			L[h].fhalf = sa[stp-1][h];
			L[h].shalf = h+i<n ? sa[stp-1][h+i] : -1;
			L[h].orig = h;
		}
		
		sort(L, L+n);
		
		sa[stp][L[0].orig] = 0;
		
		for(int h=1,cnt=0; h<n; h++)
		{
			if(L[h-1].fhalf!=L[h].fhalf || L[h-1].shalf!=L[h].shalf)
				cnt++;
		
			sa[stp][L[h].orig] = cnt;
		}
	}
}

void LCP()
{
	int len = log2(n);
	
	for(int i=1; i<n; i++)
	{
		int a = L[i-1].orig;
		int b = L[i].orig;
		int ret = 0;
		
		for(int j=len; j>=0; j--)
			if (a < n && b < n && sa[j][a] == sa[j][b])
			{
				a += (1<<j);
				b += (1<<j);
				ret += (1<<j);
			}
		sol += ret;
		lcp[i] = ret;
	}
}

int main()
{
	scanf("%s" ,s);
	
	n = strlen(s);
	
	suffix_array();
	
	LCP();
	
	printf("%d" ,n*(n+1)/2-sol);
}
