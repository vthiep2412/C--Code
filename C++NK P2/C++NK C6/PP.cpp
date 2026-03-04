#include <iostream>
#include <array>

using namespace std;

const int MAX = 1000001;
struct PreCom {
    int sumDiv[MAX]{0};

    constexpr PreCom() {
        for (int i = 1; i < MAX; ++i) {
            for (int j = 2 * i; j < MAX; j += i) {
                sumDiv[j] += i;
            }
        }
    }
};
static constexpr PreCom data;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PP.inp", "r", stdin);
	freopen("PP.out", "w", stdout);
	int l, r;
	cin>>l>>r;

	int cnt = 0;
	for (int i = l; i <= r; ++i) {
		if (data.sumDiv[i] > i) {
			cnt++;
		}
	}

	cout<<cnt;

    return 0;
}