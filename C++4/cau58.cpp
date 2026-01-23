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

void capitalizeFirstLetter(string& str) {
    bool newWord = true;

    for (char& ch : str) {
        if (isspace(ch)) {
            newWord = true;
        } else if (newWord) {
            ch = toupper(ch);
            newWord = false;
        }
    }
}

int main()
{
    string a;
    getline(cin,a);
    vector<string> b = splitString(a);
    a.clear();
    for (int i = 0; i < b.size(); i++)
    {
        a += b[i] + " ";
    }
    capitalizeFirstLetter(a);
    cout << a;
    return 0;
}