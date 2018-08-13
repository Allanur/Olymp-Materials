//#include <string.h>
#include <iostream>

const int MAXN = 5000001;

bool ret;
char w;
int n,sz,last,ln,c;
int s[MAXN],len[MAXN],link[MAXN],to[MAXN][2];

int get_link(int v)
{
	while(s[n-len[v]-2]!=s[n-1])
		v = link[v];
	return v;
}

int main()
{std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);
	//std::cin >> w;
	
	sz = 2;
	link[0] = 1;
	len[1] = -1;
	s[n++] = -1;
	
	//ln = (int)w.length();
	//ln = strlen(w);
	
	//for (int i=0; i<ln; i++)
	while(std::cin>>w)
	{
		//c = w[i]-'a';
		c = w-'a';
		
		ret = 0;
		s[n++] = c;
		last = get_link(last);
		
		if (!to[last][c])
		{
			ret = 1;
			len[sz] = len[last]+2;
			link[sz] = to[get_link(link[last])][c];
			to[last][c] = sz++;
		}
		
		last = to[last][c];
		
		std::cout << ret;
	}
}
