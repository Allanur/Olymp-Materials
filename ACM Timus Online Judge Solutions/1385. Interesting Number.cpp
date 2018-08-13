# include <iostream>

using namespace std;

int n;

int main (){
ios_base::sync_with_stdio(false);
cin.tie(NULL);	
	
	cin >> n;
	
	if (n==1)
		cout << 14;
	
	else if (n==2)
		cout << 155;
	
	else{
		cout << 1575;
		
		for (int i = 0; i < n-3; i++)	cout << 0;
	}
	
	return 0;
}
