#include <bits/stdc++.h>
using namespace std;
bool areBeside(const vector<string> &order, const string &a, const string &b) {
    for (int i = 0; i + 1 < (int)order.size(); i++) {
        if ((order[i] == a && order[i+1] == b) ||
            (order[i] == b && order[i+1] == a))
            return true;
    }
    return false;
}

vector<string> getCowOrder(int N, const vector<pair<string, string>>& cond) {
    set<string> cows;
    for (const auto& p : cond) {
        cows.insert(p.first);
        cows.insert(p.second);
    }
    vector<string> cowList(cows.begin(), cows.end());
    sort(cowList.begin(), cowList.end());
    do {
        bool ok = true;
        for (auto &p : cond) {
            if (!areBeside(cowList, p.first, p.second)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return cowList;
        }
    } while (next_permutation(cowList.begin(), cowList.end()));
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    map<string,int> map{
        {"Emily", 1},
        {"Garen", 1},
        {"Jinx", 1},
        {"Krixi", 1},
        {"Leona", 1},
        {"Jinx", 1},
        {"Max", 1},
        {"Toro", 1},
        {"Yasuo", 1}
    };
    vector<pair<string,string>> cond;
    for (int i = 0; i < N; i++) {
        string X, tmp, Y;
        cin >> X;
        for (int j = 0; j < 4; j++) cin >> tmp;
        cin >> Y;
        cond.push_back({X, Y});
    }
    vector<string> result = getCowOrder(N, cond);
    for (const string &name : result) {
        map[name] = 0;
    }
    for (const auto &p : map) {
        if (p.second == 1) {
            cout << p.first << "\n";
        }
    }
    for (const string &name : result) {
        cout << name << "\n";
    }
    return 0;
}