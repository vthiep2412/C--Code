    #include <iostream>
    #include <cmath>

    using namespace std;

    int main() {
        int n;
        cin >> n;

        int cnt = 0;

        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                cnt += 2;
            }
        }

        return 0;
    }
