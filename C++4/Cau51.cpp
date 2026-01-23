#include <bits/stdc++.h>

using namespace std;

vector<string> splitString(const string& str) {
    char delimiter = ' ';
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    return tokens;
}

int main() {
    string a,b;
    getline(cin,a);
    getline(cin,b);
    vector<string> c = splitString(a), d = splitString(b);
    int cnt=0;
    for(int j=0;j<d.size();j++){
        for(const auto i:c){
            if(i==d[j])
            {cnt++;}
        }
    }
    cout<<cnt;
    return 0;
}
