# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
# include <stdio.h>

# define lh size()

using namespace std;

int n;
string oper,user,pass;
vector < pair < string ,string > > r,li;
vector < string > lo;

int reg(string name, string psw, bool c){
	for (int i = 0; i < r.lh; i++)
		if (r[i].first==name)
			return 1;
	if (c)					
		r.push_back(make_pair(name, psw));
	return 0;
}
int login (string name, string pass){
	for (int i = 0; i < r.lh; i++)
		if (r[i].first==name && r[i].second!=pass)
			return 2;
	for (int i = 0; i < li.lh; i++)
		if (li[i].first==name)
			return 1;
	li.push_back(make_pair(name,pass));

	return 0;
}
int logout (string user){
	for (int i = 0; i < li.lh; i++){
		if (li[i].first==user){
			swap(li[i], li[li.lh-1]);
			li.pop_back();
			return 0;	
		}	
	}
	return 1;
}
int main (){
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> oper;
		
		if (oper=="register"){
			cin >> user >> pass;
			if (reg(user,pass,1))
				cout << "fail: user already exists\n";
			else
				cout << "success: new user added\n";
		}
		
		else if (oper=="login"){
			cin >> user >> pass;
			if (!reg(user,pass,0))
				cout << "fail: no such user\n";
			else if(login(user,pass)==1)
				cout << "fail: already logged in\n";
			else if(login(user,pass)==2)
				cout << "fail: incorrect password\n";
			else
				cout << "success: user logged in\n";
		}
		
		else{
			cin >> user;
			if (!reg(user,"asd",0))
				cout << "fail: no such user\n";
			else if (logout(user)==0)
				cout << "success: user logged out\n";
			else
				cout << "fail: already logged out\n";
		}
		
	}	
return 0;
}
/*
register user1 1
success: new user added
register user2 2
success: new user added
register user3 3
success: new user added
logout user2
fail: already logged out
login user1 3
fail: incorrect password
login user2 2
success: user logged in
logout user3
fail: already logged out
*/
