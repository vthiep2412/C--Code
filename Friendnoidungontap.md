**Mục lục**

**PHẦN 1: SỐ HỌC & TOÁN HỌC……………………………………3**

1.  Tìm ước, số nguyên tố, sàng nguyên tố……………………………………3

**PHẦN 1: SỐ HỌC & TOÁN HỌC**

**1\. Tìm ước, Số nguyên tố**

*   **Nguyên lý tối ưu:** Thay vì duyệt từ đến , ta chỉ cần duyệt từ đến . Vì các ước luôn đi theo cặp: nếu là ước của thì / cũng là ước của .
*   **Dấu hiệu nhận biết:** Bài yêu cầu đếm số ước, tính tổng các ước, hoặc kiểm tra tính chất số nguyên tố với giới hạn (duyệt căn ), hoặc cần kiểm tra nhiều số liên tục (dùng Sàng).

**Code kiểm tra nguyên tố & Tìm ước:**

#include <bits/stdc++.h>

using namespace std;

// 1. Kiểm tra số nguyên tố tối ưu O(sqrt(N))

bool isPrime(long long n) {

if (n < 2) return false;

for (long long i = 2; i \* i <= n; i++) {

if (n % i == 0) return false;

}

return true;

}

// 2. Hàm tìm tất cả các ước O(sqrt(N))

vector<long long> findDivisors(long long n) {

vector<long long> divisors;

for (long long i = 1; i \* i <= n; i++) {

if (n % i == 0) {

divisors.push\_back(i);

if (i != n / i) { // Tránh trùng lặp nếu n là số chính phương

divisors.push\_back(n / i);

}

}

}

sort(divisors.begin(), divisors.end()); // Sắp xếp lại nếu cần

return divisors;

}

\--------------------------------------------------------------------------------------------------------

**2\. Sàng nguyên tố (Sieve of Eratosthenes) :** Dùng khi bài yêu cầu liệt kê/kiểm tra nguyên tố cho hàng loạt số nhỏ hơn .

**Code sàng:**

const int MAX = 1e7 + 5;

bool prime\[MAX\];

void sieve() {

memset(prime, true, sizeof(prime));

prime\[0\] = prime\[1\] = false;

for (int p = 2; p \* p < MAX; p++) {

if (prime\[p\] == true) {

for (int i = p \* p; i < MAX; i += p)

prime\[i\] = false; // Đánh dấu các bội số là false

}

}

}

**3\. Sàng mở rộng (Segmented Sieve)**

*   **Nguyên lý:** Sàng Eratosthenes bình thường chỉ cân được mảng cỡ vì giới hạn bộ nhớ. Nhưng nếu đề bắt tìm các số nguyên tố trong đoạn với lên tới thì mảng bình thường sẽ bị TLE. Sàng mở rộng giải quyết bằng cách: Chỉ cần tìm các số nguyên tố (cỡ ), sau đó dùng chính các số nguyên tố này để "đánh dấu" các bội số của chúng nằm trong đoạn .
*   **Dấu hiệu nhận biết:** Bài yêu cầu đếm, tính tổng hoặc in ra các số nguyên tố trong đoạn với rất lớn (lên tới ) nhưng chênh lệch lại nhỏ (khoảng ).

**Code:**

#include <bits/stdc++.h>

using namespace std;

// Sàng mở rộng tìm các số nguyên tố trong đoạn \[L, R\]

void segmentedSieve(long long L, long long R) {

// Bước 1: Sàng các số nguyên tố cơ bản đến căn R

long long limit = sqrt(R);

vector<bool> mark(limit + 1, true);

vector<long long> primes;

for (long long p = 2; p \* p <= limit; p++) {

if (mark\[p\]) {

for (long long i = p \* p; i <= limit; i += p)

mark\[i\] = false;

}

}

for (long long p = 2; p <= limit; p++) {

if (mark\[p\]) primes.push\_back(p);

}

// Bước 2: Dùng các số nguyên tố vừa tìm để sàng đoạn \[L, R\]

vector<bool> isPrime(R - L + 1, true);

for (long long p : primes) {

// Tìm bội số nhỏ nhất của p lớn hơn hoặc bằng L

long long base = (L / p) \* p;

if (base < L) base += p;

if (base == p) base += p; // Không đánh dấu chính bản thân số p

for (long long j = base; j <= R; j += p) {

isPrime\[j - L\] = false;

}

}

// L = 1 thì 1 không phải là số nguyên tố

if (L == 1) isPrime\[0\] = false;

// In kết quả hoặc đếm

for (long long i = 0; i <= R - L; i++) {

if (isPrime\[i\]) cout << (i + L) << " ";

}

cout << "\\n";

}

**4\. UCLN (GCD) & BCNN (LCM)**

*   **Nguyên lý:** Thuật toán Euclid (chia dư liên tiếp). Rất may là C++14 đã có sẵn hàm \_\_gcd(a, b) nên không cần tự viết dài dòng.
*   **Công thức LCM:** . Chú ý nhân dễ bị tràn số (overflow), nên tính kiểu .

**Code GCD & LCM:**

long long GCD(long long a, long long b) {

return \_\_gcd(a, b); // Hàm có sẵn của C++

}

long long LCM(long long a, long long b) {

return (a / \_\_gcd(a, b)) \* b; // Tránh tràn số so với (a\*b)/gcd

}

**5\. Số Chính Phương & Số Hoàn Thiện**

*   **Số chính phương:** Số có căn bậc 2 là một số nguyên (VD: 4, 9, 16).
*   **Số hoàn thiện:** Tổng các ước (không tính chính nó) bằng chính nó (VD: 6 = 1 + 2 + 3).

**Code số chính phương & số hoàn thiện:**

// Kiểm tra số chính phương

bool isPerfectSquare(long long n) {

if (n < 0) return false;

long long sq = round(sqrt(n)); // Dùng round để tránh sai số dấu phẩy động

return sq \* sq == n;

}

// Kiểm tra số hoàn thiện

bool isPerfectNumber(long long n) {

if (n <= 1) return false;

long long sum = 1; // 1 luôn là ước

for (long long i = 2; i \* i <= n; i++) {

if (n % i == 0) {

sum += i;

if (i != n / i) sum += n / i;

}

}

return sum == n;

}

**6\. Phân tích thừa số nguyên tố nhanh (Trial Division) + Đếm/Tổng ước từ phân tích**

· **Nguyên lý:** Nếu chia hết cho thì chia liên tục để lấy số mũ. Chỉ cần thử tới .  
· **Dấu hiệu nhận biết:** Đề yêu cầu **phân tích** , **đếm số ước**, **tổng ước**, **tìm ước nguyên tố**, **kiểm tra dạng** , hoặc nhiều phép xử lý dựa trên factorization.

**Code:**

#include <bits/stdc++.h>

using namespace std;

// trả về vector (prime, exponent)

vector<pair<long long,int>> primeFactorize(long long n){

vector<pair<long long,int>> f;

for(long long p=2; p\*p<=n; ++p){

if(n%p==0){

int cnt=0;

while(n%p==0){ n/=p; cnt++; }

f.push\_back({p,cnt});

}

}

if(n>1) f.push\_back({n,1});

return f;

}

// số lượng ước: d(n)= Π (ai+1)

long long countDivisors\_fromFactor(const vector<pair<long long,int>>& f){

long long ans=1;

for(auto &e: f) ans \*= (e.second + 1LL);

return ans;

}

// tổng ước: σ(n)= Π (1+p+...+p^ai)

long long sumDivisors\_fromFactor(const vector<pair<long long,int>>& f){

long long ans=1;

for(auto &e: f){

long long p=e.first; int a=e.second;

long long term=1, cur=1;

for(int i=0;i<a;i++){

cur \*= p;

term += cur;

}

ans \*= term;

}

return ans;

}

\--------------------------------------------------------------------------------------------------------

**7\. Sàng “SPF” (Smallest Prime Factor) để phân tích nhiều số cực nhanh**

· **Nguyên lý:** Tiền xử lý mảng spf\[x\] = ước nguyên tố nhỏ nhất của x. Khi cần phân tích một số x, cứ lấy p=spf\[x\] rồi chia dần.  
· **Dấu hiệu nhận biết:** Có **nhiều truy vấn** factorization/đếm ước/tổng ước với (N cỡ 10^6–10^7).

**Code:**

struct SPF\_Sieve {

int N;

vector<int> spf; // smallest prime factor

SPF\_Sieve(int n): N(n), spf(n+1, 0){

for(int i=2;i<=N;i++){

if(spf\[i\]==0){

spf\[i\]=i;

if(1LL\*i\*i<=N){

for(long long j=1LL\*i\*i;j<=N;j+=i)

if(spf\[(int)j\]==0) spf\[(int)j\]=i;

}

}

}

spf\[1\]=1;

}

vector<pair<int,int>> factorize(int x){

vector<pair<int,int>> f;

while(x>1){

int p=spf\[x\], cnt=0;

while(x%p==0){ x/=p; cnt++; }

f.push\_back({p,cnt});

}

return f;

}

};

**8\. Lũy thừa nhanh (Binary Exponentiation) + nghịch đảo modulo**

· **Nguyên lý:** Dựa trên biểu diễn nhị phân của số mũ. Mỗi bước bình phương cơ số, nếu bit = 1 thì nhân vào đáp án.  
· **Dấu hiệu nhận biết:** Có cụm “ rất lớn”, “mod ”, “nghịch đảo modulo”, “chia dưới modulo”.

**Code:**

#include <bits/stdc++.h>

using namespace std;

long long modPow(long long a, long long e, long long mod){

a%=mod;

long long r=1%mod;

while(e>0){

if(e&1) r = (\_\_int128)r\*a % mod;

a = (\_\_int128)a\*a % mod;

e >>= 1;

}

return r;

}

// chỉ đúng khi mod là số nguyên tố và a không chia hết cho mod

long long modInv\_Fermat(long long a, long long mod){

return modPow(a, mod-2, mod);

}

**PHẦN 2: XỬ LÝ CHUỖI & CƠ SỐ**

Phần này hay gặp trong mấy bài thao tác văn bản hoặc xử lý số lớn (số có 100 chữ số chẳng hạn thì phải dùng chuỗi).

**1\. Kiểm tra chuỗi đối xứng (Palindrome)**

*   Nguyên lý: Đừng có đảo ngược cả chuỗi rồi so sánh, cách này tốn bộ nhớ. Chỉ cần duyệt một nửa từ đầu đến giữa, so sánh ký tự thứ i với ký tự thứ n-i-1.

**Code tối ưu:**

bool isPalindrome(string s) {

int n = s.length();

for (int i = 0; i < n / 2; i++) {

if (s\[i\] != s\[n - 1 - i\]) return false;

}

return true;

}

\--------------------------------------------------------------------------------------------------------

**2\. Chuyển đổi String - Number**

Đừng viết tay vòng for nhân 10, dùng hệ sinh thái có sẵn.

*   String sang số: stoi() (thành int), stoll() (thành long long).
*   Số sang string: to\_string().

**Code chuyển đổi:**

string s = "123456";

int num = stoi(s);

long long bigNum = stoll(s);

int x = 987;

string strX = to\_string(x);

**3\. Chuyển đổi cơ số (Hệ 10 sang hệ 2 và ngược lại)**

*   **Hệ 10 -> Hệ 2:** Chia liên tiếp cho 2 lấy phần dư, sau đó đảo ngược chuỗi dư.
*   **Hệ 2 -> Hệ 10:** Đi từ cuối lên đầu, nhân từng chữ số với $2^0, 2^1, 2^2...$

**Code chuyển đổi:**

// Hệ 10 sang Hệ 2

string decToBin(long long n) {

if (n == 0) return "0";

string bin = "";

while (n > 0) {

bin += to\_string(n % 2);

n /= 2;

}

reverse(bin.begin(), bin.end()); // Hàm đảo chuỗi có sẵn

return bin;

}

// Hệ 2 sang Hệ 10

long long binToDec(string bin) {

long long dec = 0;

long long power = 1; // 2^0

for (int i = bin.length() - 1; i >= 0; i--) {

if (bin\[i\] == '1') dec += power;

power \*= 2;

}

return dec;

}

**4\. Chuyển đổi cơ số tổng quát (Hệ 10 ↔ hệ b; hệ a → hệ b)**

· **Nguyên lý:**

*   10 → b: chia liên tiếp cho b lấy dư.
*   b → 10: nhân dồn value = value\*b + digit.
*   a → b: đổi về 10 rồi sang b (khi còn fit trong 64-bit).  
    · **Dấu hiệu nhận biết:** Đề có “hệ cơ số b”, “đổi cơ số”, “chuyển sang hexa/base 36…”.

**Code:**

#include <bits/stdc++.h>

using namespace std;

int val(char c){

if('0'<=c && c<='9') return c-'0';

if('A'<=c && c<='Z') return c-'A'+10;

if('a'<=c && c<='z') return c-'a'+10;

return 1000;

}

char dig(int v){

if(v<10) return char('0'+v);

return char('A'+(v-10));

}

// base -> decimal (chỉ khi kết quả không vượt long long)

long long baseToDec(const string& s, int base){

long long x=0;

for(char c: s){

int d=val(c);

if(d>=base) throw runtime\_error("invalid digit");

// kiểm soát tràn nếu cần:

if(x > (LLONG\_MAX - d)/base) throw overflow\_error("overflow");

x = x\*base + d;

}

return x;

}

string decToBase(long long n, int base){

if(n==0) return "0";

bool neg=false;

if(n<0){ neg=true; n=-n; }

string r;

while(n>0){

r.push\_back(dig(n%base));

n/=base;

}

if(neg) r.push\_back('-');

reverse(r.begin(), r.end());

return r;

}

string baseAToBaseB(const string& s, int a, int b){

long long x = baseToDec(s,a);

return decToBase(x,b);

}

**5\. Chuyển cơ số khi số cực lớn (dạng chuỗi hệ 10) → hệ b**

· **Nguyên lý:** Mô phỏng phép chia “số rất lớn” cho b trên chuỗi: mỗi vòng lấy **thương mới** và **dư**.  
· **Dấu hiệu nhận biết:** Đề cho **n có hàng trăm/hàng nghìn chữ số**, yêu cầu đổi sang base 2/8/16… (không fit 64-bit).

**Code:**

#include <bits/stdc++.h>

using namespace std;

// chia chuỗi thập phân cho base, trả về (thuong, du)

pair<string,int> divBigDecByBase(const string& s, int base){

string q;

long long rem=0;

for(char c: s){

rem = rem\*10 + (c-'0');

int digit = (int)(rem/base);

rem %= base;

if(!q.empty() || digit!=0) q.push\_back(char('0'+digit));

}

if(q.empty()) q="0";

return {q, (int)rem};

}

string bigDecToBase(string s, int base){

if(s=="0") return "0";

string res;

while(s!="0"){

auto \[q, r\] = divBigDecByBase(s, base);

res.push\_back(r<10? char('0'+r) : char('A'+(r-10)));

s=q;

}

reverse(res.begin(), res.end());

return res;

}

\--------------------------------------------------------------------------------------------------------

**6\. Xử lý bit căn bản và nâng cao (Bit Manipulation)**

**Nguyên lý:** Máy tính làm việc cực kỳ nhanh với hệ nhị phân. Xử lý bit là việc dùng các toán tử & (AND), | (OR), ^ (XOR), ~ (NOT), << (Dịch trái), >> (Dịch phải) để tối ưu thời gian chạy xuống mức .

**Dấu hiệu nhận biết:** Các bài toán bật/tắt công tắc, kiểm tra tính chẵn lẻ nhanh, hoặc thao tác trên "Tập con" (đã có trong phần duyệt tập con ). Đặc biệt hay gặp trong bài toán tìm số xuất hiện lẻ lần (dùng XOR).

**Cheatsheet Code & Các hàm:**

#include <bits/stdc++.h>

using namespace std;

void bitTricks() {

int x = 10; // Giả sử x = 10 (Hệ 2: 1010)

int i = 2; // Thao tác với bit thứ 2 (đếm từ 0 từ phải sang)

// 1. Kiểm tra bit thứ i đang là 0 hay 1

bool checkBit = (x >> i) & 1;

// 2. Bật bit thứ i lên 1 (Dùng OR)

int turnOn = x | (1 << i);

// 3. Tắt bit thứ i về 0 (Dùng AND và NOT)

int turnOff = x & ~(1 << i);

// 4. Đảo thái bit thứ i (0 thành 1, 1 thành 0 - Dùng XOR)

int flipBit = x ^ (1 << i);

// 5. Nhân/Chia 2 cực nhanh (Không dùng dấu \* /)

int nhan2 = x << 1; // Tương đương x \* 2

int chia2 = x >> 1; // Tương đương x / 2

// 6. Kiểm tra số lẻ siêu tốc

bool isOdd = x & 1; // True nếu x lẻ, False nếu x chẵn

// --- CÁC HÀM CÓ SẴN CỦA TRÌNH BIÊN DỊCH (GCC) ---

int mask = 29; // 11101 hệ nhị phân

// Đếm số lượng bit 1 (rất hay dùng trong quy hoạch động trạng thái)

int count1 = \_\_builtin\_popcount(mask);

// Dùng \_\_builtin\_popcountll(mask) nếu mask là long long

}

**PHẦN 3: TÌM KIẾM, SẮP XẾP & MẢNG**

Ở cấp tỉnh, thuật toán Trâu (O(N^2)) chết chắc. Em phải nắm vững Binary Search và các kĩ thuật xử lý mảng .

**1\. Mảng cộng dồn (Prefix Sum) & Mảng hiệu (Difference Array)**

*   **Mảng cộng dồn (Prefix Sum):** \* _Dấu hiệu:_ Đề bắt "tính tổng các phần tử từ vị trí L đến R" lặp đi lặp lại hàng nghìn lần (Q truy vấn).
    *   _Nguyên lý:_ Dựng mảng P\[i\] = P\[i-1\] + A\[i\]. Tổng đoạn $\[L, R\]$ chỉ cần tính bằng P\[R\] - P\[L-1\] trong thời gian .
*   **Mảng hiệu (Difference Array):**
    *   _Dấu hiệu:_ Đề bắt "tăng/giảm giá trị X cho toàn bộ phần tử từ vị trí L đến R" lặp đi lặp lại nhiều lần.
    *   _Nguyên lý:_ Dựng mảng D\[i\] = A\[i\] - A\[i-1\]. Khi cần tăng đoạn lên , chỉ cần làm: D\[L\] += X và D\[R+1\] -= X. Xong hết truy vấn thì cộng dồn mảng D lại để ra mảng kết quả.

\--------------------------------------------------------------------------------------------------------

**2\. Tìm kiếm nhị phân (Binary Search)**

*   **Dấu hiệu:** Đề bài tìm kiếm trên một tập **ĐÃ SẮP XẾP** hoặc tìm một giới hạn "nhỏ nhất thỏa mãn" hoặc "lớn nhất thỏa mãn".
*   **Bí kíp STL:** Thay vì tự viết, C++ có hàm sẵn:
    *   binary\_search(a, a+n, x): Trả về true/false xem x có trong mảng a không.
    *   lower\_bound(a, a+n, x): Trả về con trỏ tới phần tử **ĐẦU TIÊN** .
    *   upper\_bound(a, a+n, x): Trả về con trỏ tới phần tử **ĐẦU TIÊN** .

**Code tìm kiếm nhị phân:**

// Cách tự viết Binary Search chuẩn (áp dụng chặt nhị phân kết quả)

int binarySearch(int arr\[\], int n, int x) {

int left = 0, right = n - 1;

while (left <= right) {

int mid = left + (right - left) / 2; // Tránh tràn số

if (arr\[mid\] == x) return mid; // Tìm thấy

if (arr\[mid\] < x) left = mid + 1; // Bỏ nửa trái

else right = mid - 1; // Bỏ nửa phải

}

return -1; // Không tìm thấy

}

\--------------------------------------------------------------------------------------------------------

**3\. Sắp xếp (Sort)**

Về Quick Sort, cần hiểu ý tưởng "chia để trị" (chọn pivot, chia mảng thành phần nhỏ hơn và phần lớn hơn). Sort trong STL chạy hàm IntroSort (pha trộn giữa Quick Sort, Heap Sort, Insertion Sort).

**Code sắp xếp:**

sort(a, a + n); // Mảng thường

sort(v.begin(), v.end(), greater<int>()); // Vector, sắp xếp giảm dần

\--------------------------------------------------------------------------------------------------------

**4\. Tìm kiếm tuần tự (Linear Search)**

· **Nguyên lý:** Duyệt lần lượt từ đầu tới cuối, gặp phần tử cần tìm thì dừng.  
· **Dấu hiệu nhận biết:** Dữ liệu **nhỏ**, mảng **chưa sắp xếp**, chỉ có **1 lần tìm** hoặc bé.

**Code:**

int linearSearch(const vector<int>& a, int x){

for(int i=0;i<(int)a.size();i++)

if(a\[i\]==x) return i;

return -1;

}

\--------------------------------------------------------------------------------------------------------

**5\. Chặt nhị phân kết quả (Binary Search on Answer)**

· **Nguyên lý:** Khi đáp án là một giá trị và ta có hàm kiểm tra check(mid) **đơn điệu** (true/false theo 1 chiều), dùng binary search để tìm **nhỏ nhất/lớn nhất** thỏa.  
· **Dấu hiệu nhận biết:** Có câu kiểu: “**nhỏ nhất** sao cho…”, “**lớn nhất** thỏa…”, “tối thiểu hóa/tối đa hóa” + có thể kiểm tra được với một mid.

Code:

// tìm nhỏ nhất x trong \[lo, hi\] sao cho check(x)==true

long long firstTrue(long long lo, long long hi, function<bool(long long)> check){

long long ans = hi+1;

while(lo<=hi){

long long mid = lo + (hi-lo)/2;

if(check(mid)){

ans = mid;

hi = mid-1;

}else lo = mid+1;

}

return ans; // nếu = hi+1 nghĩa là không tồn tại

}

**6\. Quick Sort**

· **Nguyên lý:** Chọn pivot, chia mảng thành 2 phần (< pivot) và (> pivot) rồi đệ quy.  
· **Dấu hiệu nhận biết:** Khi đề/giáo viên yêu cầu **tự cài quicksort**, hoặc cần hiểu “chia để trị – partition”.

**Code:**

#include <bits/stdc++.h>

using namespace std;

int partitionHoare(vector<long long>& a, int l, int r){

long long pivot = a\[l + (r-l)/2\];

int i=l-1, j=r+1;

while(true){

do{i++;} while(a\[i\] < pivot);

do{j--;} while(a\[j\] > pivot);

if(i>=j) return j;

swap(a\[i\], a\[j\]);

}

}

void quickSort(vector<long long>& a, int l, int r){

if(l>=r) return;

int p = partitionHoare(a, l, r);

quickSort(a, l, p);

quickSort(a, p+1, r);

}

**7\. Chia để trị & đếm số nghịch thế (Merge Sort)**

**Nguyên lý:** Quick Sort cũng là một dạng chia để trị. Nhưng ở cấp tỉnh, mô hình chia để trị kinh điển nhất mà giám khảo rất thích ra là thuật toán Trộn mảng (Merge Sort) để giải quyết bài toán "Đếm số nghịch thế" (Inversion Count).

**Dấu hiệu nhận biết:** Đề yêu cầu đếm số cặp vị trí sao cho nhưng . Hoặc tính số lần đổi chỗ ít nhất các phần tử kề nhau để mảng được sắp xếp tăng dần. Nếu duyệt trâu vòng for thì bị TLE, dùng Merge Sort sẽ kéo xuống .

**Code đếm nghịch thế bằng Merge Sort:**

#include <bits/stdc++.h>

using namespace std;

long long mergeAndCount(vector<int>& arr, int l, int m, int r) {

int n1 = m - l + 1;

int n2 = r - m;

vector<int> L(n1), R(n2);

for (int i = 0; i < n1; i++) L\[i\] = arr\[l + i\];

for (int j = 0; j < n2; j++) R\[j\] = arr\[m + 1 + j\];

int i = 0, j = 0, k = l;

long long inv\_count = 0;

while (i < n1 && j < n2) {

if (L\[i\] <= R\[j\]) {

arr\[k++\] = L\[i++\];

} else {

arr\[k++\] = R\[j++\];

// Nếu L\[i\] > R\[j\] thì tất cả các phần tử sau L\[i\] cũng lớn hơn R\[j\]

inv\_count += (n1 - i);

}

}

while (i < n1) arr\[k++\] = L\[i++\];

while (j < n2) arr\[k++\] = R\[j++\];

return inv\_count;

}

long long mergeSortAndCount(vector<int>& arr, int l, int r) {

long long inv\_count = 0;

if (l < r) {

int m = l + (r - l) / 2;

inv\_count += mergeSortAndCount(arr, l, m);

inv\_count += mergeSortAndCount(arr, m + 1, r);

inv\_count += mergeAndCount(arr, l, m, r);

}

return inv\_count;

}

// Khi gọi hàm ở main(): long long ans = mergeSortAndCount(a, 0, n - 1);

**PHẦN 4: TỔ HỢP, TẬP HỢP & THUẬT TOÁN NÂNG CAO**

**1\. Đệ quy & Quay lui (Backtracking)**

*   **Dấu hiệu:** "Liệt kê tất cả các tổ hợp", "Sinh các hoán vị", "Đường đi trên lưới". Thường giới hạn dữ liệu rất nhỏ ($N \\le 20$).
*   **Nguyên lí (Form chuẩn):** Thử tất cả các khả năng cho vị trí thứ $i$. Nếu thỏa mãn thì đi tiếp vị trí $i+1$. Cần có bước "trả lại trạng thái" (quay lui).

**Code:**

// Ví dụ sinh chuỗi nhị phân độ dài n

int x\[100\];

int n = 3;

void tryBinary(int i) {

for (int j = 0; j <= 1; j++) {

x\[i\] = j;

if (i == n) {

// In kết quả

for (int k = 1; k <= n; k++) cout << x\[k\];

cout << endl;

} else {

tryBinary(i + 1); // Đệ quy bước tiếp theo

}

}

}

Lưu ý: Nếu chỉ cần sinh hoán vị, C++ có sẵn next\_permutation(v.begin(), v.end()).

**2\. Về STL nâng cao (Cấu trúc dữ liệu có sẵn)**

Đây là những code dùng cho các thuật toán khác nhau:

*   queue, stack: Dùng cho BFS (Tìm đường đi ngắn nhất đồ thị không trọng số) và DFS (Duyệt sâu).
*   priority\_queue: Hàng đợi ưu tiên. Thường xuyên dùng cho bài toán tìm Max/Min động hoặc thuật toán Dijkstra.
*   set, map: Lưu trữ theo cây Đỏ-Đen. Thêm/xóa/tìm kiếm mất . Đặc biệt map để đếm tần số xuất hiện của một phần tử nhanh.
*   unordered\_map: Giống map nhưng không sắp xếp, tốc độ là (tuy nhiên đi thi thỉnh thoảng bị chặn testcase hash collision nên dùng cẩn thận).
*   multiset: Giống set, được cài đặt bằng Cây Đỏ Đen giúp tự động sắp xếp và tìm kiếm trong . Khác ở chỗ nó cho phép các giá trị giống nhau cùng tồn tại. Rất hợp để duy trì mảng luôn được sắp xếp trong khi ta liên tục thêm/xóa phần tử. Tuy nhiên, khi dùng hàm erase(), nếu truyền vào **giá trị**, nó sẽ xóa TẤT CẢ các phần tử có giá trị đó. Muốn chỉ xóa 1 phần tử, phải truyền vào **iterator**.
*   multimap: Giống map , được cài đặt bằng Cây Đỏ Đen, nên các phần tử khi thêm vào sẽ **tự động được sắp xếp tăng dần theo Key**, thời gian thêm/xóa/tìm kiếm vẫn siêu nhanh là . Khác ở chỗ nó cho phép các giá trị giống nhau cùng tồn tại. Tuy nhiên, không thể dùng cú pháp m\[key\] = value, nếu dùng sẽ xảy ra LỖI. Muốn truyền dữ liệu vào, phải truyền bằng hàm insert().

\--------------------------------------------------------------------------------------------------------

**3\. Các cấu trúc dữ liệu lớn: Segment Tree & Fenwick Tree (BIT)**

Segment Tree và Fenwick Tree là kiến thức CỰC KỲ QUAN TRỌNG ở cấp thành phố.

*   **Dấu hiệu:** Bài có dạng "Update điểm/đoạn, Truy vấn tổng/max/min trên đoạn". Mảng cộng dồn không dùng được cho bài có cập nhật (Update), lúc đó phải dùng Segment Tree.
*   _Lời khuyên:_ Form của Segment Tree dài và cần luyện gõ nhiều lần cho quen tay. Cây BIT (Fenwick) thì ngắn gọn hơn dùng để tính tổng mảng. Nếu chưa vững, học BIT trước.

\--------------------------------------------------------------------------------------------------------

**4\. Tổ hợp – Chỉnh hợp – Giai thừa (có/không modulo)**

· **Nguyên lý:**

*   Giai thừa: .
*   Chỉnh hợp: .
*   Tổ hợp: .  
    · **Dấu hiệu nhận biết:** Đề đếm “số cách chọn”, “số cách sắp”, “chọn k từ n”, “mod 1e9+7”.

**Code:**

**(A) Không modulo, n nhỏ (≤ 20) – dùng long long/unsigned long long:**

unsigned long long factULL(int n){

unsigned long long r=1;

for(int i=2;i<=n;i++) r\*= (unsigned long long)i;

return r;

}

unsigned long long nPr(int n,int k){

if(k<0 || k>n) return 0;

unsigned long long r=1;

for(int i=0;i<k;i++) r\*= (unsigned long long)(n-i);

return r;

}

unsigned long long nCr\_small(int n,int k){

if(k<0 || k>n) return 0;

k=min(k,n-k);

unsigned long long r=1;

for(int i=1;i<=k;i++){

r = r\*(unsigned long long)(n-k+i)/ (unsigned long long)i; // chia hết

}

return r;

}

**(B) Có modulo PRIME (thường 1e9+7) – precompute fact/ifact:**

static const long long MOD = 1000000007LL;

long long modPow(long long a, long long e){

long long r=1%MOD; a%=MOD;

while(e){

if(e&1) r=(\_\_int128)r\*a%MOD;

a=(\_\_int128)a\*a%MOD;

e>>=1;

}

return r;

}

long long inv(long long a){ return modPow(a, MOD-2); }

struct Comb {

int N;

vector<long long> fact, ifact;

Comb(int n): N(n), fact(n+1), ifact(n+1){

fact\[0\]=1;

for(int i=1;i<=N;i++) fact\[i\]=fact\[i-1\]\*i%MOD;

ifact\[N\]=inv(fact\[N\]);

for(int i=N;i>=1;i--) ifact\[i-1\]=ifact\[i\]\*i%MOD;

}

long long C(int n,int k){

if(k<0 || k>n) return 0;

return fact\[n\]\*ifact\[k\]%MOD\*ifact\[n-k\]%MOD;

}

long long A(int n,int k){

if(k<0 || k>n) return 0;

return fact\[n\]\*ifact\[n-k\]%MOD;

}

};

**(C) Không cần nghịch đảo / mod không chắc prime → Pascal O(n^2)**

vector<vector<long long>> buildC(int n, long long mod){

vector<vector<long long>> C(n+1, vector<long long>(n+1,0));

for(int i=0;i<=n;i++){

C\[i\]\[0\]=C\[i\]\[i\]=1%mod;

for(int j=1;j<i;j++){

C\[i\]\[j\]=(C\[i-1\]\[j-1\]+C\[i-1\]\[j\])%mod;

}

}

return C;

}

**5\. Duyệt tập con (Subset Enumeration / Bitmask)**

· **Nguyên lý:** Một tập con của n phần tử tương ứng với mask n bit.  
· **Dấu hiệu nhận biết:** n nhỏ (≤ 20~25), yêu cầu “duyệt mọi tập con”, “chọn/bỏ”, “tối ưu trên tập con”.

**Code:**

// duyệt tất cả subset của {0..n-1}

for(int mask=0; mask<(1<<n); mask++){

// xử lý subset mask

}

// duyệt các submask của một mask cho trước

for(int sub=mask; sub; sub=(sub-1)&mask){

// sub là 1 tập con khác rỗng của mask

}

// nhớ thêm sub=0 nếu cần

**PHẦN 5: ĐỒ THỊ**

**1\. DFS (Duyệt sâu) – đồ thị / lưới**

· **Nguyên lý:** Đi sâu tới khi không đi được nữa thì quay lại.  
· **Dấu hiệu nhận biết:** “đếm thành phần liên thông”, “tìm đường tồn tại”, “loang”, “kiểm tra chu trình”.

**Code:**

int n;

vector<vector<int>> adj;

vector<int> vis;

void dfs(int u){

vis\[u\]=1;

for(int v: adj\[u\]){

if(!vis\[v\]) dfs(v);

}

}

\--------------------------------------------------------------------------------------------------------

**2\. BFS (Duyệt rộng) – đường đi ngắn đồ thị không trọng số**

· **Nguyên lý:** BFS theo lớp, đảm bảo lần đầu tới đỉnh là **ngắn nhất** (số cạnh).  
· **Dấu hiệu nhận biết:** “đường đi ngắn nhất” nhưng **không có trọng số**, bài mê cung, lưới 4 hướng.

**Code:**

vector<int> bfs\_dist(int s){

vector<int> dist(n, -1);

queue<int> q;

dist\[s\]=0; q.push(s);

while(!q.empty()){

int u=q.front(); q.pop();

for(int v: adj\[u\]){

if(dist\[v\]==-1){

dist\[v\]=dist\[u\]+1;

q.push(v);

}

}

}

return dist;

}

**PHẦN 6: QUY HOẠCH ĐỘNG**

**1\. DP cơ bản (đếm / tối ưu)**

**· Nguyên lý:** Trạng thái dp\[...\] lưu đáp án tốt nhất (hoặc số cách) cho bài con; chuyển trạng thái từ nhỏ → lớn.**· Dấu hiệu nhận biết:** Có “**tối ưu**”, “**số cách**”, “chia thành bài con”, vừa (1e3–1e5 tùy dạng).

**Code:**

**(A) 0/1 Knapsack (tối ưu giá trị):**

// w\[i\], val\[i\], capacity W

vector<long long> dp(W+1, 0);

for(int i=0;i<n;i++){

for(int cap=W; cap>=w\[i\]; --cap){

dp\[cap\]=max(dp\[cap\], dp\[cap-w\[i\]\]+val\[i\]);

}

}

**(B) LIS O(n log n):**

vector<int> tail;

for(int x: a){

auto it = lower\_bound(tail.begin(), tail.end(), x);

if(it==tail.end()) tail.push\_back(x);

else \*it=x;

}

int LIS = (int)tail.size();

**(C) DP đường đi trên lưới (đếm số cách):**

// dp\[i\]\[j\] = dp\[i-1\]\[j\] + dp\[i\]\[j-1\] nếu ô không bị chặn

**PHẦN 7: CẤU TRÚC DỮ LIỆU NÂNG CAO**

**1\. Fenwick Tree (BIT) – point update, range sum query**

· **Nguyên lý:** BIT lưu tổng theo “lowbit”, update và query đều O(logN).  
· **Dấu hiệu nhận biết:** Nhiều truy vấn **cập nhật điểm** + hỏi **tổng đoạn**.

**Code:**

struct Fenwick {

int n;

vector<long long> bit;

Fenwick(int n=0){init(n);}

void init(int n\_){ n=n\_; bit.assign(n+1,0); }

void add(int idx, long long val){

for(; idx<=n; idx += idx&-idx) bit\[idx\] += val;

}

long long sumPrefix(int idx){

long long r=0;

for(; idx>0; idx -= idx&-idx) r += bit\[idx\];

return r;

}

long long sumRange(int l,int r){

if(l>r) return 0;

return sumPrefix(r)-sumPrefix(l-1);

}

};

**2\. Segment Tree (có Lazy) – range add, range sum**

· **Nguyên lý:** Cây đoạn lưu thông tin trên đoạn; lazy propagation để dồn cập nhật đoạn.  
· **Dấu hiệu nhận biết:** Update **cả đoạn** + query **cả đoạn** (sum/min/max).

**Code:**

struct SegTree {

int n;

vector<long long> st, lazy; // sum

SegTree(int n=0){init(n);}

void init(int n\_){

n=n\_;

st.assign(4\*n+5,0);

lazy.assign(4\*n+5,0);

}

void build(int p, int l, int r, const vector<long long>& a){

if(l==r){ st\[p\]=a\[l\]; return; }

int m=(l+r)/2;

build(p\*2,l,m,a);

build(p\*2+1,m+1,r,a);

st\[p\]=st\[p\*2\]+st\[p\*2+1\];

}

void push(int p, int l, int r){

if(lazy\[p\]==0) return;

st\[p\] += lazy\[p\]\*(r-l+1);

if(l!=r){

lazy\[p\*2\] += lazy\[p\];

lazy\[p\*2+1\] += lazy\[p\];

}

lazy\[p\]=0;

}

void rangeAdd(int p,int l,int r,int i,int j,long long val){

push(p,l,r);

if(j<l || r<i) return;

if(i<=l && r<=j){

lazy\[p\]+=val;

push(p,l,r);

return;

}

int m=(l+r)/2;

rangeAdd(p\*2,l,m,i,j,val);

rangeAdd(p\*2+1,m+1,r,i,j,val);

st\[p\]=st\[p\*2\]+st\[p\*2+1\];

}

long long rangeSum(int p,int l,int r,int i,int j){

push(p,l,r);

if(j<l || r<i) return 0;

if(i<=l && r<=j) return st\[p\];

int m=(l+r)/2;

return rangeSum(p\*2,l,m,i,j) + rangeSum(p\*2+1,m+1,r,i,j);

}

};

**PHẦN 8: TRIE**

**Trie – lưu từ, đếm prefix**

· **Nguyên lý:** Mỗi node là 1 prefix, cạnh là ký tự. Insert/Search O(length).  
· **Dấu hiệu nhận biết:** “đếm số từ có prefix…”, “từ điển”, “autocomplete”, “kiểm tra tiền tố”.

**Code:**

struct Trie {

struct Node {

int nxt\[26\];

int endCnt; // số từ kết thúc tại đây

int passCnt; // số từ đi qua đây

Node(){

memset(nxt, -1, sizeof(nxt));

endCnt=passCnt=0;

}

};

vector<Node> tr;

Trie(){ tr.push\_back(Node()); }

void insert(const string& s){

int u=0;

for(char ch: s){

int c=ch-'a';

if(tr\[u\].nxt\[c\]==-1){

tr\[u\].nxt\[c\]= (int)tr.size();

tr.push\_back(Node());

}

u=tr\[u\].nxt\[c\];

tr\[u\].passCnt++;

}

tr\[u\].endCnt++;

}

bool search(const string& s){

int u=0;

for(char ch: s){

int c=ch-'a';

if(tr\[u\].nxt\[c\]==-1) return false;

u=tr\[u\].nxt\[c\];

}

return tr\[u\].endCnt>0;

}

int countPrefix(const string& pref){

int u=0;

for(char ch: pref){

int c=ch-'a';

if(tr\[u\].nxt\[c\]==-1) return 0;

u=tr\[u\].nxt\[c\];

}

return tr\[u\].passCnt + tr\[u\].endCnt; // tùy cách bạn tăng passCnt

}

};

**PHẦN 10: HÌNH HỌC TÍNH TOÁN CƠ BẢN**

**Vector – tích có hướng – giao đoạn**

· **Nguyên lý:** Dùng cross product để xét hướng rẽ (orientation), diện tích, giao nhau.  
· **Dấu hiệu nhận biết:** Bài có điểm/đoạn thẳng/đa giác: “thẳng hàng”, “bên trái/bên phải”, “giao”, “diện tích”.

**Code:**

struct Point{

long long x,y;

};

Point operator-(Point a, Point b){ return {a.x-b.x, a.y-b.y}; }

long long cross(Point a, Point b){ return a.x\*b.y - a.y\*b.x; }

int orient(Point a, Point b, Point c){

long long v = cross(b-a, c-a);

if(v==0) return 0;

return (v>0)? 1 : -1; // 1: CCW, -1: CW

}

bool onSegment(Point a, Point b, Point p){

if(orient(a,b,p)!=0) return false;

return min(a.x,b.x)<=p.x && p.x<=max(a.x,b.x) &&

min(a.y,b.y)<=p.y && p.y<=max(a.y,b.y);

}

bool segIntersect(Point a, Point b, Point c, Point d){

int o1=orient(a,b,c), o2=orient(a,b,d);

int o3=orient(c,d,a), o4=orient(c,d,b);

if(o1\*o2<0 && o3\*o4<0) return true;

if(o1==0 && onSegment(a,b,c)) return true;

if(o2==0 && onSegment(a,b,d)) return true;

if(o3==0 && onSegment(c,d,a)) return true;

if(o4==0 && onSegment(c,d,b)) return true;

return false;

}