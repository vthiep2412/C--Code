#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char, ll> mp;

void addtomap(string str){
	for(char &c: str){
		if(isalpha(c)) mp[toupper(c)]++;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ThongKe.INP", "r", stdin);
    freopen("ThongKe.OUT", "w", stdout);
	
	string s;
    while(cin>>s){
		addtomap(s);
	}
	for(pair<char, ll> &oi: mp){
		cout<<oi.first << " "<< oi.second<<"\n";
	}
    return 0;
}