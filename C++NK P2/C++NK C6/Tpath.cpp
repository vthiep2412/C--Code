#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

const int N = 1e7 + 5;

vector<char> isPrime(N, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int a[1505][1505];
int dr[] = {0, 1, 1};
int dc[] = {1, 0, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("Tpath.inp", "r", stdin);
    freopen("Tpath.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }
    ll sum=0, cnt=0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (isPrime[a[r][c]]) {
                cnt++;
                sum += a[r][c];
            }
            for (int d = 0; d < 3; d++) {
                int CurNum=a[r][c];
                for (int len = 1; len <= 5; len++) {
                    int nr = r + len * dr[d];
                    int nc = c + len * dc[d];
                    if(nr >= n or nc >= m) break;
                    CurNum = CurNum * 10 + a[nr][nc];
                    if(isPrime[CurNum]) {cnt++; sum+=CurNum;}
                }
            }
        }
    }
    cout<<cnt<<" "<<sum;
    return 0;
}