# include <iostream>
# include <limits.h>
# include <string>

using namespace std;

string s="36";
int n,v[99999];

void func(int x)
{
	int k=0,q=90000,mx=INT_MAX,o,i=0;
	
	while(x!=0)
	{
		i++;
		for (int h = s.length()-1; h >= 0; h--)
		{
			int l=(x%10)*(s[h]-48);
			
			if(l>=10) v[q-1]+=l/10,v[q--]+=l%10;
			else v[q--]+=l;
			
			mx=min(mx,q);
		}
		q=90000-i,x/=10;
	}
	
	s.clear();
	
	for	(int i = 90000; i >= mx; i--)
		if(v[i]>=10) o=v[i],v[i]=v[i]%10,v[i-1]+=o/10;

	k=0;
	
	for	(int i = mx; i <=90000; i++)
	{
		if(v[i]!=0)
			s.push_back(v[i]+48),v[i]=0,k=1;
		else if(v[i]==0 && k==1)
			s.push_back(48);
	}
}

int main ()
{	
	cin >> n;
	
	for (int i = 2; i <= n; i++)
		func(55);
	
	cout << s;
	
return 0;	
}
