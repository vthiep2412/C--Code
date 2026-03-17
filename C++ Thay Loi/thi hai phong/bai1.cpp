#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("bai1.INP", "r", stdin);
	freopen("bai1.OUT", "w", stdout);
    ll sum=0, n, cnt=0;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		bool check = (s.back() == '0' || s.back() == '5');  
		for(const char &c: s){
			sum += c - '0';
		}
		if(check and sum%5==0) cnt++;
		sum=0;
	}
	cout<<cnt;
    return 0;
}