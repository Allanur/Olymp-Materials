# include <stdio.h>
# include <iostream>

using namespace std;

int n,m,x,o,l,r,largest;
int t[125009];

void max_heap ()	// ---Build_Max_Heap
{
	while (x > 1 && t[x/2] < t[x])
	{
		swap (t[x/2], t[x]);
		x/=2;
	}
}
void heapify()
{
	while(1)
	{
		largest = x,
		l = x*2,
		r = x*2+1;
		
		if (l<=m && t[l] > t[x])
			largest = l;
		if (r<=m && t[r] > t[largest])
			largest = r;
		
		if (x==largest)
			break;
			
		swap(t[x], t[largest]);
		x = largest;
	}
}

int main ()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

	scanf ("%d" ,&n);
	m = n/2+1;
	
	for (int i = 1; i <= n; i++)
	{	
		scanf ("%d" ,&o);
		
		if (i<=m)
			t[i] = o, x = i, max_heap();
		
		else if (t[1] > o)
			t[1] = o, x = 1, heapify();
	}
	
	l = t[1], r = max (t[2], t[3]);
	
	printf ("%.1lf" ,(n%2 ? l*1.0: l/2.0 + r/2.0) );
	
	return 0;
}
