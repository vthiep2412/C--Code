#include <bits/stdc++.h>
using namespace std;

// Sàng Eratosthenes để tìm các số nguyên tố nhỏ hơn hoặc bằng n
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    return is_prime;
}

/*cac ham tim kiem nhi phan*/
int binsearchBILarger(vector<int>& a, int x) {
    int k = lower_bound(a.begin(), a.end(), x) - a.begin();
    if (k < a.size() && a[k] == x) return k;
    return -1;
}

int binsearchBISmaller(vector<int>& a, int x) {
    int k = upper_bound(a.begin(), a.end(), x) - a.begin();
    return k - 1; 
}

int binsearchBI(vector<int>& a, int x) {
    int k = lower_bound(a.begin(), a.end(), x) - a.begin();
    if (k == a.size()) return -1;
    return k;
}

// Tìm kiếm nhị phân thủ công
template <typename T>
int binsearch(const vector<T>& a, const T& x) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] < x) l = mid + 1;
		else r = mid - 1;
    }
    return -1;
}

// Tìm vị trí phần tử lớn nhất mà <= x (Lower Bound tương đối)
int binsearchSmaller(const vector<int>& a, int n, int x) {
    int l = 0, r = n - 1, res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= x) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

// Tìm vị trí phần tử nhỏ nhất mà >= x (Tương đương std::lower_bound)
int binsearchLarger(const vector<int>& a, int n, int x) {
    int l = 0, r = n - 1, res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

// Tính base^exp. Chú ý: có thể bị tràn số với base và exp lớn.
long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res *= base;
        base *= base;
        exp /= 2;
    }
    return res;
}

// Lấy tất cả các ước của một số nguyên
vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) { // Tránh lặp lại ước nếu n là số chính phương
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}
// Kiểm tra số nguyên tố
bool prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    long long c2 = sqrt(n);
    for (long long i = 5; i <= c2; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
// Đếm nhanh số lượng ước
long long countDivisors(long long n){
    long long cnt=0;
    for(long long i=1;i*i<=n;++i){
        if(n%i==0){
            cnt++;
            if(i*i!=n) cnt++;
        }
    }
    return cnt;
}
// Lấy chữ số đầu tiên của một số
int getFirstDigit(int num) {
	if (num == 0) return 0;
    num = abs(num);
    int digits = log10(num);
    return num / pow(10, digits);
}
// Kiểm tra xem một số có phải là lũy thừa của 2 không
bool isPowerofTwo(int n) {
    return n && (!(n&(n-1)));
}
// Tìm bội chung nhỏ nhất
int lcm(int a, int b) {
    return (a / __gcd(a, b)) * b;
}
// Tính tổng các số trong một khoảng
long long sumRange(long long l, long long r) {
    return (l + r) * (r - l + 1) / 2;
}
// Tính tổng các số chia hết cho k trong một khoảng
long long sumDivisible(long long l, long long r, long long k) {
    long long first = (l + k - 1) / k * k;
    if (first > r) return 0;
    long long last = r / k * k;
    long long cnt = (last - first) / k + 1;
    return (first + last) * cnt / 2;
}
// Cho phép in ra một cặp (pair)
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}
// In một vector
template <typename T>
void printvector(T &a){
    for(auto& x: a) cout << x << " "; cout << "\n";
}
// Chuyển đổi mọi kiểu dữ liệu sang chuỗi bằng stringstream
template <typename T>
string toString(const T& value) {
    stringstream ss;
    ss << value;
    return ss.str();
}
// Chuyển đổi chuỗi sang long long bằng stringstream
long long stoLLong(const string& s) {
    stringstream ss(s);
    long long val;
    ss >> val;
    return val;
}
// Sắp xếp nhanh vector sử dụng bucket sort
vector<int> fastBucketSort(const vector<int>& a, int max_val) {
    vector<int> count(max_val + 1, 0);
    for (int num : a) count[num]++;
    vector<int> sorted;
    sorted.reserve(a.size());
    for (int i = 0; i <= max_val; ++i) {
        sorted.insert(sorted.end(), count[i], i);
    }
    return sorted;
}
// Hàm chuyển đổi một số dạng chuỗi từ hệ thập phân sang hệ cơ số bất kỳ (hỗ trợ cơ số 2 đến 36)
string convertToBase(const string& n_str, int to) {
    long long n = stoLLong(n_str);
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        int rem = n % to;
        if (rem < 10) {
            res += (char)(rem + '0');
        } else {
            res += (char)(rem - 10 + 'A');
        }
        n /= to;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    return 0;
}