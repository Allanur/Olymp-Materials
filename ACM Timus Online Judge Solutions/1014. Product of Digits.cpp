# include <iostream>
# include <algorithm>

using namespace std;

int n,one,a=1,k;
int out[1009],v[10]={0};

int com ( void const *x, void const *y )
{
	int a = * ( int * ) x;
	int b = * ( int * ) y;
	return a-b;
}

int main ()
{
	cin >> n;

	if ( n==0 )	{ cout << "10"; return 0;}
	if ( n<10 )	{ cout << n; return 0;}
	
	for ( int i = 9; i >= 2; i-- )
		while ( n%i==0 )
			v[i]++,n/=i,one=1;
	
	if ( one==0 || n>1 ) { cout << "-1"; return 0; }
	
	for ( int i = 1; i < 10; i++ )
		while ( v[i]!=0 )
		{
			a=1;
			while ( a*i<10 && v[i]>0 )	a*=i,v[i]--;			
			out[k]=a,k++;
		}
	
	qsort ( out,k,sizeof(int),com );
	
	for ( int i = 0; i < k; i++ )
		cout << out[i];
	
return 0;	
}
