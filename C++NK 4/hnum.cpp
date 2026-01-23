#include <iostream>

using namespace std;

int main() {
    freopen("HNUM.INP", "r", stdin);
    freopen("HNUM.OUT", "w", stdout);

    int n;
    cin >> n;

    bool b = false;
    
    for (int i = 10; i <= n; i++) {
        int num = i, cnt = 0, numTemp=num;
        // dem so chu so cua num
        while (numTemp > 0) {
            numTemp /= 10;
            cnt++;
        }

        if (cnt % 2 == 1) continue; // tranh cac so co so chu so le

        numTemp = num;
        int s1 = 0, s2 = 0,a = cnt/2;
        // tinh tong cac chu so cua num, nua sau
        for (int j = 0; j < a; j++)
        {
            s1 += numTemp % 10;
            numTemp /= 10;
        }
        // tinh tong cac chu so cua num, nua truoc
        for (int j = 0; j < a; j++)
        {
            s2 += numTemp % 10;
            numTemp /= 10;
        }
        if (s1 == s2) {
            cout << i << endl;
            b = true;
        }
    }

    if (!b) cout << -1 << endl;

    return 0;
}
