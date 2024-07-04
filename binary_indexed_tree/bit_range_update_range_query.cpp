#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 9;

// Fenwick Tree (Binary Indexed Tree)

// Time Complexity - O(log n)
// Space Complexity - O(n)
template<class T>
struct BIT {
  T b1[maxn], b2[maxn];
  BIT() {
    memset(b1, 0, sizeof(b1));
    memset(b2, 0, sizeof(b2));
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
  void range_update(int l, int r, T val) {
    update(b1, l, x);
    update(b1, r + 1, -x);
    update(b2, l, x * (l - 1));
    update(b2, r + 1, -x * r);
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
  T prefix_sum(int index) {
    return query(b1, index) * index - query(b2, index);
  }
  T range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
  }
};

int main() {
  // ...
}
