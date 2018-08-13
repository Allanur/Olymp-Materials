#include <iostream>

using namespace std;

long long  n,m;

int main()
{
    cin>>n>>m;
    
    if( m >= n )
		cout << 2*(n-1) << "\n";

    else if( n > m )
		cout << (2*m)-1 << "\n";

return 0;
}
