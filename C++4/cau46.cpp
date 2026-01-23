#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    map<char, int> char_count;
    for(char i : a)
    {
        char_count[i]++;
    }
    for(auto i : char_count)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}