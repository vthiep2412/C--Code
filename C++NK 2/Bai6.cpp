#include <bits/stdc++.h>
using namespace std;

int solve(int n, int a, int b) {
    int max = 0, x = 0, y = 0, j = 0;
    
    while (y <= n / b) {
        x = (n - b * y) / a;
        j = a * x + b * y;
        if (j > max) {
            max = j;
        }
        y++;
    }
    return max;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int ketqua = solve(n, a, b);
    cout << ketqua;
    return 0;
}


//ax+by<=n
//x  formula
//ax+by<=n
//ax<=n-by
//x<=(n-by)/a

//tim khoang cach
//by<=n
//y<=n/b

//tim x
//for(int y = 0; y<=n/b;y++)
//x = (n-by)/a
//if (max < a*x+b*y)
//max = a*x + b*y
//else cout<<max
//return 0