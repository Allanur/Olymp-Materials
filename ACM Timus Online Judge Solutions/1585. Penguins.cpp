#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

string s;

string penguins1="Emperor Penguin";
string penguins2="Little Penguin";
string penguins3="Macaroni Penguin";

int n;
 
int main ()
{
	int a=0,b=0,c=0;
	cin>>n;
	scanf("\n");
	for(int i=0;i<n+1;i++)
 
	{  
	getline(cin,s);	
	if(s==penguins1)
	a++;
	if(s==penguins2)
	b++;
	if(s==penguins3)
	c++;		
	}
	
		if(a>b && a>c)
	cout<<"Emperor Penguin";
	else if(b>a && b>c)
		cout<<"Little Penguin";
	else if(c>a && c>b)
	cout<<"Macaroni Penguin";
	getchar (); getchar ();
return 0;
}

 
