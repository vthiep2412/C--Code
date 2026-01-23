#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1000;

void removeExtraSpace(string &a)
{
    while(a.find("  ") <= a.length())
    {a.erase(a.find("  "), 1);}
}


void splitString(const string& str, string tokens[], int& tokenCount) {
    char delimiter = ' ';
    stringstream ss(str);
    string token;
    tokenCount = 0;

    while (getline(ss, token, delimiter)) {
        if (!token.empty()) {
            tokens[tokenCount++] = token;
        }
    }
}

int main() {
    string a, b;
    getline(cin, a);
    removeExtraSpace(a);


    cout << a;
    return 0;
}
