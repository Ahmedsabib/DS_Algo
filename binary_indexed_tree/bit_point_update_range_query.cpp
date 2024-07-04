#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)1e5 + 5;

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

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  BIT<int> bit(n + 1);
  for (int i = 1; i <= n; ++i) {
    bit.update(i, a[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      int index, val;
      cin >> index >> val;
      a[index] += val;
      bit.update(index, val);
    }
    else if (x == 2) {
      int l, r;
      cin >> l >> r;
      cout << bit.query(l, r) << '\n';
    }
  }
  return 0;
}