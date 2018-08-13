#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef double lf;
typedef long long lld;

string s;
int n, sol, cur;
string cas[][9] = {
{"Alice","Ariel","Aurora","Phil","Peter","Olaf","Phoebus","Ralph","Robin"},
{"Bambi","Belle","Bolt","Mulan","Mowgli","Mickey","Silver","Simba","Stitch"},
{"Dumbo","Genie","Jiminy","Kuzko","Kida","Kenai","Tarzan","Tiana","Winnie"}
};

int main()
{
	cin >> n;
	
	for (int i=0; i<n; i++)
	{
		cin >> s;
		
		for (int a=0; a<3; a++)
			for (int b=0; b<9; b++)
				if (s == cas[a][b])
					sol += abs(cur-a),
						cur = a;
	}
			
	cout << sol;
}
