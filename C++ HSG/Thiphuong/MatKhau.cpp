#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<char> se;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MATKHAU.INP", "r", stdin);
    freopen("MATKHAU.OUT", "w", stdout);
    string s, res;
	cin>>s;
	for(char &c: s){
		if(isalpha(c) and se.find(toupper(c)) == se.end()){
			res.push_back(c);
			se.insert(toupper(c));
		}
	}
	cout<<res;
    return 0;
}