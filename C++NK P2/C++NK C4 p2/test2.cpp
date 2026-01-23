#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

long long oi(string s){
	//string stream
	long long res = 0;
	stringstream ss(s);
	ss >> res;
	return res;
}

void rshift(string &s){
	string temp;
	int n = s.size()-1;
	temp += s.back();
	temp += s.substr(0, n);
	s = temp;
}

int main() {
	ios_base::sync_with_stdio(0);    cin.tie(0);
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	string s, temp;
	long long maxVal = -1;
	cin >> s;
	maxVal = oi(s); // Consider the original string
	temp = s;
	rshift(temp);
	if (oi(temp) > maxVal) maxVal = oi(temp);
	while (temp != s){
		rshift(temp);
		long long val = oi(temp);
		if (val > maxVal) maxVal = val;
	}
	cout << maxVal << '\n';
	return 0;
}