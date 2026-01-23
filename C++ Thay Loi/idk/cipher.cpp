#include <bits/stdc++.h>
using namespace std;

vector<string> words;
string cur;
vector<string> a;

void gen(int idx) {
    if (idx == (int)words.size()) {
        a.push_back(cur);
        return;
    }
    for (char c : words[idx]) {
        cur.push_back(c);
        gen(idx + 1);
        cur.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k,x,itemp = 0;
    string s,temp;
    cin>>n>>m>>k>>x;
    cin.ignore();
    getline(cin, s);
    for(int i = 0;i<m;i++){
        cin>>temp;
        words.push_back(temp);
    }
    gen(0);
    string tempofans = a[x-1];
    for(char c:s){
        if(c=='#'){
            cout<<tempofans[itemp++];
        } else {
            cout<<c;
        }
    }
}
