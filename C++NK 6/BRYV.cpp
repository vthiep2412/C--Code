#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("BRVY.INP", "r", stdin);
    // freopen("BRVY.OUT", "w", stdout);

    int x, dx, d, dd, t, dt, v, dv;
    cin >> x >> dx;
    cin >> d >> dd;
    cin >> t >> dt;
    cin >> v >> dv;

    // Tìm gcd của 4 độ dài để giới hạn các l có thể kiểm tra
    auto gcd = [](int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    };

    int g = gcd(gcd(dx, dd), gcd(dt, dv));
    int maxArea = 0;
    int bestK = 0, bestL = 0;

    // Tìm tất cả ước số của g
    for (int l = 1; l * l <= g; ++l) {
        if (g % l == 0) {
            // Thử ước l
            for (int u : {l, g / l}) {
                int kx = x * dx / u;
                int kd = d * dd / u;
                int kt = t * dt / u;
                int kv = v * dv / u;
                int k = min({kx, kd, kt, kv});
                int area = (k * u) * (k * u);
                if (area > maxArea) {
                    maxArea = area;
                    bestK = k;
                    bestL = u;
                }
            }
        }
    }

    // In kết quả
    cout << maxArea << "\n";
    cout << (x * dx) / bestL / bestK << " ";
    cout << (d * dd) / bestL / bestK << " ";
    cout << (t * dt) / bestL / bestK << " ";
    cout << (v * dv) / bestL / bestK << "\n";

    return 0;
}
