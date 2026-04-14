#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <cstring>

using namespace std;

typedef chrono::high_resolution_clock::time_point TimePt;
#define NOW chrono::high_resolution_clock::now()
#define DUR(s, e) chrono::duration<double, milli>(e - s).count()

// --- 1. RADIX LSD (Stable) ---
void radixLsd(vector<int>& a) {
  int n = a.size();
  vector<int> b(n);
  for (int s = 0; s < 32; s += 8) {
    int count[256] = {0};
    for (int x : a) count[(x >> s) & 0xFF]++;
    for (int i = 1; i < 256; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) b[--count[(a[i] >> s) & 0xFF]] = a[i];
    a = b;
  }
}

// --- 2. RADIX MSD (Stable) ---
void msdHelper(vector<int>& a, int l, int r, int bit, vector<int>& b) {
  if (l >= r || bit < 0) return;
  int count[3] = {0};
  for (int i = l; i <= r; i++) count[((a[i] >> bit) & 1) + 1]++;
  count[1] += count[0];
  for (int i = l; i <= r; i++) b[l + count[(a[i] >> bit) & 1]++] = a[i];
  for (int i = l; i <= r; i++) a[i] = b[i];
  int m = l + count[0];
  msdHelper(a, l, m - 1, bit - 1, b);
  msdHelper(a, m, r, bit - 1, b);
}
void radixMsd(vector<int>& a) {
  vector<int> b(a.size());
  msdHelper(a, 0, a.size() - 1, 30, b);
}

// --- 3. QUICK SORT (Hoare Partition) ---
void quickHoare(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int p = a[l + (r - l) / 2], i = l - 1, j = r + 1;
  while (true) {
    do i++; while (a[i] < p);
    do j--; while (a[j] > p);
    if (i >= j) break;
    swap(a[i], a[j]);
  }
  quickHoare(a, l, j);
  quickHoare(a, j + 1, r);
}

// --- 4. SMOOTHSORT (Dijkstra) ---
const int LP[] = {1, 1, 3, 5, 9, 15, 25, 41, 67, 109, 177, 287, 465, 753, 1219, 1973, 3193, 5167, 8361, 13529, 21891, 35421, 57313, 92735, 150049, 242785, 392835, 635621, 1028457, 1664079, 2692537, 4356617, 7049155, 11405773, 18454929, 29860703, 48315633, 78176337, 126491971, 204668309, 331160281, 535828591, 866988873};
void sift(vector<int>& a, int r, int p) {
    while (p >= 2) {
        int r2 = r - LP[p - 2] - 1;
        // Safety: ensure r2 and children are within bounds
        if (r2 < 0) break; 
        
        if (a[r - 1] >= a[r2]) {
            if (a[r] >= a[r - 1]) break;
            swap(a[r], a[r - 1]);
            r--; p--;
        } else {
            if (a[r] >= a[r2]) break;
            swap(a[r], a[r2]);
            r = r2; p -= 2;
        }
    }
}

void trinkle(vector<int>& a, int r, int p, long long b) {
    while (b > 0) {
        while (!(b & 1)) { b >>= 1; p++; }
        int r2 = r - LP[p];
        if (b == 1 || r2 < 0 || a[r2] <= a[r]) break;
        
        if (p >= 2) {
            int rc = r - 1, lc = r - 1 - LP[p - 2];
            if (lc >= 0 && (a[r2] <= a[rc] || a[r2] <= a[lc])) break;
        }
        swap(a[r], a[r2]);
        r = r2; b--;
    }
    sift(a, r, p);
}

void smoothSort(vector<int>& a) {
    int n = a.size();
    if (n < 2) return;
    int p = 1, r = 0;
    long long b = 1;
    
    // Building the Leonardo heap
    while (++r < n) {
        if ((b & 3) == 3) { b >>= 2; p += 2; b++; }
        else {
            if (p > 1 && LP[p - 1] < n - r) { b <<= 1; p--; }
            else { b <<= 1; p--; b++; }
        }
        trinkle(a, r, p, b);
    }
    
    // Tearing down and sorting
    while (--r > 0) {
        if (p < 2) {
            do { b >>= 1; p++; } while (!(b & 1));
            b--;
        } else {
            b <<= 1; p--; b++; b <<= 1; p--; b++;
            if (r - LP[p] - 1 >= 0) trinkle(a, r - LP[p] - 1, p + 1, b >> 1);
            trinkle(a, r, p, b);
        }
    }
}

// --- 5. COUNTING SORT (Stable) ---
void countingSort(vector<int>& a) {
  if (a.empty()) return;
  int minV = a[0], maxV = a[0], n = a.size();
  for (int x : a) { if (x < minV) minV = x; if (x > maxV) maxV = x; }
  vector<int> count(maxV - minV + 1, 0), b(n);
  for (int x : a) count[x - minV]++;
  for (int i = 1; i < count.size(); i++) count[i] += count[i - 1];
  for (int i = n - 1; i >= 0; i--) b[--count[a[i] - minV]] = a[i];
  a = b;
}

// --- 6. GRAVITY SORT (Bead Sort) ---
void gravitySort(vector<int>& a) {
  int n = a.size(), maxV = 0;
  for (int x : a) maxV = max(maxV, x);
  vector<int> count(maxV, 0);
  for (int x : a) for (int i = 0; i < x; i++) count[i]++;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < maxV; j++) if (count[j] >= n - i) sum++;
    a[i] = sum;
  }
}

// --- 7. MERGE SORT (Stable) ---
void mergeSort(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  mergeSort(a, l, mid); mergeSort(a, mid + 1, r);
  vector<int> b; int i = l, j = mid + 1;
  while (i <= mid && j <= r) b.push_back(a[i] <= a[j] ? a[i++] : a[j++]);
  while (i <= mid) b.push_back(a[i++]);
  while (j <= r) b.push_back(a[j++]);
  for (int k = 0; k < b.size(); k++) a[l + k] = b[k];
}

// --- 8. HEAP SORT (Unstable) ---
void heapify(vector<int>& a, int n, int i) {
  int lg = i, l = 2 * i + 1, r = 2 * i + 2;
  if (l < n && a[l] > a[lg]) lg = l;
  if (r < n && a[r] > a[lg]) lg = r;
  if (lg != i) { swap(a[i], a[lg]); heapify(a, n, lg); }
}
void heapSort(vector<int>& a) {
  int n = a.size();
  for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
  for (int i = n - 1; i > 0; i--) { swap(a[0], a[i]); heapify(a, i, 0); }
}

// --- 9. SHELL SORT (Unstable) ---
void shellSort(vector<int>& a) {
  int n = a.size();
  for (int gap = n / 2; gap > 0; gap /= 2)
    for (int i = gap; i < n; i++) {
      int t = a[i], j;
      for (j = i; j >= gap && a[j - gap] > t; j -= gap) a[j] = a[j - gap];
      a[j] = t;
    }
}

void run(string name, vector<int> data, void (*func)(vector<int>&)) {
  TimePt s = NOW; func(data); TimePt e = NOW;
  bool ok = true;
  for (size_t i = 1; i < data.size(); i++) if (data[i] < data[i - 1]) ok = false;
  printf("%-15s: %10.3f ms | Valid: %s\n", name.c_str(), DUR(s, e), ok ? "YES" : "NO");
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  mt19937 rng(1337);
  vector<int> base(n);
  TimePt sShuf = NOW;
  for (int i = 0; i < n; i++) base[i] = rng() % 5000;
  cout << "N = " << n << " | Shuffle: " << DUR(sShuf, NOW) << " ms\n---\n";

  run("Radix LSD", base, radixLsd);
  run("Radix MSD", base, radixMsd);
  run("Counting Sort", base, countingSort);
  run("Quick (Hoare)", base, [](vector<int>& v){ quickHoare(v, 0, v.size() - 1); });
  run("Merge Sort", base, [](vector<int>& v){ mergeSort(v, 0, v.size() - 1); });
  run("Smoothsort", base, smoothSort);
  run("Heap Sort", base, heapSort);
  run("Shell Sort", base, shellSort);
  run("std::sort", base, [](vector<int>& v){ sort(v.begin(), v.end()); });
  run("std::stable", base, [](vector<int>& v){ stable_sort(v.begin(), v.end()); });
  if (n <= 20000) run("Gravity Sort", base, gravitySort);

  return 0;
}