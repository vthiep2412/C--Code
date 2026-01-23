#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
	//freopen("DOIXUNG.INP", "r", stdin);
	//freopen("DOIXUNG.OUT", "w", stdout);
    string s;
	cin>>s;
	
	string t = "$#";
	for (char c : s) {
		t += c;
		t += "#";
	}
	t+= "^";
	
	int n = t.size();
	
	vector<int> p(n, 0);
	int c = 0, r = 0, maxi = 0;
	for (int i = 1; i < n-1; i++) {
		int mirror = 2*c-i;
		if(i<r) p[i] = min(p[mirror], r-i);
		while(t[i-1-p[i]] == t[i+1+p[i]]) p[i]++;
		if(i+p[i] > r){
			c=i;
			r=i+p[i];
		}
		maxi = max(p[i],maxi);
	}
	cout<<maxi;
    return 0;
}