#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N + 1), prefix(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    // dp[i][k]: tổng lớn nhất nhỏ nhất khi chia i phần tử vào k thùng
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int k = 1; k <= M; ++k) {
            for (int j = 0; j < i; ++j) {
                int max_sum = max(dp[j][k - 1], prefix[i] - prefix[j]);
                dp[i][k] = min(dp[i][k], max_sum);
            }
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}
