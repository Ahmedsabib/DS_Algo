#include <bits/stdc++.h>
 
using namespace std;
 
// Fenwick Tree (Binary Indexed Tree)
 
// Time Complexity - O(log n)
// Space Complexity - O(n)
template<class T>
struct BIT { // 1 base indexed
  int n;
  vector<T> t;
  BIT(int _n) {
    n = _n;
    t.assign(n + 1, 0);
  }
  // For query of a fixed index
  // O(log n)
  T query(int index) {
    T ans = 0;
    for (; index >= 1; index -= (index & (-index))) {
      ans += t[index];
    }
    return ans;
  }
  // For updating the points of BIT
  // O(log n)
  void update(int index, T val) {
    if (index <= 0) {
      return;
    }
    for (; index <= n; index += (index & (-index))) {
      t[index] += val;
    }
  }
  // For updating the ranges of BIT
  // O(log n)
  void update(int l, int r, T val) {
    update(l, val);
    update(r + 1, -val);
  }
  // For query of a range
  // O(log n)
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
      a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }
    BIT<int> bit(n + 1);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      ans += bit.query(a[i] - 1);
      bit.update(a[i], 1);
    }
    cout << ans << '\n';
  }
  return 0;
}