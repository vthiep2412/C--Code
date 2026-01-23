#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> generate_hamming(ll limit) {
	vector<ll> hamming;
	hamming.push_back(1);
	size_t i2 = 0, i3 = 0, i5 = 0;
	while (true) {
		ll next2 = hamming[i2] * 2;
		ll next3 = hamming[i3] * 3;
		ll next5 = hamming[i5] * 5;
		ll next = min({next2, next3, next5});
		if (next > limit) break;
		if (next != hamming.back()) hamming.push_back(next);
		if (next == next2) ++i2;
		if (next == next3) ++i3;
		if (next == next5) ++i5;
	}
	return hamming;
}

int main() {
	freopen("HAMMING.INP", "r", stdin);
	freopen("HAMMING.OUT", "w", stdout);
	ll t;
	cin >> t;
	vector<ll> queries(t);
	ll max_query = 0;
	for (ll i = 0; i < t; ++i) {
		cin >> queries[i];
		if (queries[i] > max_query) max_query = queries[i];
	}
	vector<ll> hamming = generate_hamming(max_query);
	for (ll i = 0; i < t; ++i) {
		ll left = 0, right = hamming.size() - 1, pos = -1;
		while (left <= right) {
			ll mid = left + (right - left) / 2;
			if (hamming[mid] == queries[i]) {
				pos = mid;
				break;
			} else if (hamming[mid] < queries[i]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		if (pos != -1)
			cout << (pos + 1) << endl;
		else
			cout << "Not in sequence" << endl;
	}
	return 0;
}