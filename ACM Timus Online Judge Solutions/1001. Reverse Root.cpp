#include <math.h> 
#include <fstream>
#include <vector>
using namespace std;
	long long n;
	double m;
	vector < double > ab;
int main ()
{
	ifstream fin("file.in");
	ofstream fout("file.out");
	
 
	while(!fin.eof())
	{
	fin>>n;
 
	m=(double)(sqrt((double)n));	
		ab.push_back(m);
	}
	 
	reverse(ab.begin(),ab.end()); 
	
	fout.precision(4);
	
	for(int i=0;i<ab.size();i++)
 	fout<<fixed<<ab[i]<<"\n";
	
	return 0;
}
