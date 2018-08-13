# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <string>
# include <math.h>

# define lh(X) (int)X.length()
# define rev(X) reverse(X.begin(), X.end())

using namespace std;

int n, s, x, sol[10009];
string a, b;
string d[59][1009];
bool one;

void add(){	
	x = 0;
	if ( lh(a) < lh(b) ){
		rev(a);
		for (int i = 0; i < lh(b)-lh(a)+i; i++)	a+='0';
		rev(a);
	}
	else{
		rev(b);
		for (int i = 0; i < lh(a)-lh(b)+i; i++)	b+='0';
		rev(b);	
	}
	
	for (int i = lh(a)-1; i >= 0; i--){
		x += ((a[i]-48) + (b[i]-48));	
		a[i] = (x%10 + 48);		
		x/=10;
	}
	if (x)
		rev(a), a+=(x+48), rev(a);
}

void mul(){

	int o = 10000, k = o, mn = o, e = 0;
	
	for (int i = lh(a)-1; i >= 0; i--)
	{
		for (int h = lh(b)-1; h >= 0; h--)
		{
			
			e = (a[i]-48) * (b[h]-48);
			
			sol[k] += e;
			if (sol[k] > 9) 	sol[k-1] += sol[k]/10, sol[k]%=10;
				
			k--;
			
			if (sol[k] > 9) 	sol[k-1] += sol[k]/10, sol[k]%=10;
		}
		o--;
		mn = min (o,k);
		k = o;
	}
	
	for (int i = mn; i <= 10000; i++)
	{
		if (!one && sol[i])		one = 1;
		if (one)	cout << sol[i];
	}
}
int main()
{
	fill(d[1], d[51], "0");
	
	cin >> n >> s;
	
	if (s%2 || n*2*9<s)
	{
		cout << 0;
		return 0;
	}
	
	for (int i = 0; i <= 18; i+=2)
		d[1][i] = "1";
	
	for (int i = 2; i <= n; i++)
		for (int h = 0; h <= s; h+=2)
		{
			a = "0";
			for (int j = h; j >= max(h-18, 0); j-=2)
				b = d[i-1][j], add();	
			d[i][h] = a;
		}
	a = d[n][s], b = d[n][s];
	mul();
	
	return 0;
}
