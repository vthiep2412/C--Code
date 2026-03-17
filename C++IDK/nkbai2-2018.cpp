#include <bits/stdc++.h>
using namespace std;

bool kt(long long n){
    if(n < 2) return false;
    if(n == 2 || n == 3 || n == 5) return true;
    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;    
    const long long c2 = sqrt(n);
    for(int i = 7; i <= c2; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

bool check(long long num, const string &s) {
    string snum = to_string(num);
    if (snum.size() != s.size()) return false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '?' && s[i] != snum[i])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    string s, snum;
    cin >> s;
    const int c = s.size();
    for(int i = 0; i < c; i++){
        snum.append("9");
    }
    long long n = stoll(snum);
    for(long long i = n; i > 7; i--){
        if(kt(i) && check(i, s)){
            cout << i;
            return 0;
        }
    }
    return 0;
}
