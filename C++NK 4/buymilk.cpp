#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BUYMILK.INP", "r", stdin);
    freopen("BUYMILK.OUT", "w", stdout);

    long long a, n, C;
    cin >> a >> n >> C;

    long long total = C/a;
    long long bonus = total / n;
    long long all = total + bonus;
    cout << all;

    return 0;
}
