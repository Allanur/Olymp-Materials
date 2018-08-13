# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

int n, a, b, c, x;
int A[109], B[109], aa = 1, bb = 1;
unsigned long long int AA = 1, BB = 1;

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;		
		(x==1 ? a++ : (x==2 ? b++ : c++));
	}
	
	for (int i = 1; i <= n; i++)	A[aa++] = i;
	for (int i = 1; i <= a; i++)	B[bb++] = i;
	for (int i = 1; i <= b; i++)	B[bb++] = i;
	for (int i = 1; i <= c; i++)	B[bb++] = i;
	
	for (int i = 1; i < aa; i++)
	{
		for (int j = 1; j < bb; j++)
		{
			x = __gcd(A[i], B[j]);
			A[i] /= x;
			B[j] /= x;
		}
	}
	
	for (int i = 1; i < bb; i++)	BB *= B[i];
	
	for (int i = 1; i < aa; i++)
	{
		AA *= A[i];
		if (AA/BB >= 6)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	
	return 0;
}
