#include <stdio.h>
#include <string.h>
#include <algorithm>

const int MAXN = 100009;

using namespace std;

char w[MAXN];
int n,ln,last,sz,c;
int s[MAXN],len[MAXN],link[MAXN],to[MAXN][26];

int getlink(int v)
{
	while(s[n-len[v]-2]!=s[n-1])
		v = link[v];
	return v;
}

int main()
{
	sz = 2;
	link[0] = 1;
	len[1] = -1;
	s[n++] = -1;
	
	scanf("%s" ,w);
	
	ln = strlen(w);
	
	for (int i=0; i<ln; i++)
	{
		c = w[i]-'a';
		
		s[n++] = c;
		
		last = getlink(last);
		
		if(!to[last][c])
		{
			len[sz] = len[last]+2;
			link[sz] = to[getlink(link[last])][c];
			to[last][c] = sz++;
		}
		
		last = to[last][c];
		
		printf("%d " ,sz-2);
	}
}
//aaabbbababbaaaa
