/**
Problem:
We are given an array a1,a2,a3...an and an integer q. The i th of the next q
lines has an integer ti, describing the type of query.
- If ti = 0, then you are given two other integers, idxi and xi,
meaning that we should make aidx = xi.
- If ti = 1 then you are given three integers li, ri, xi. You should answer with the smallest value v
in the range [li,ri] such that x ≤ v. If there is none, print -1.

**/

/**
Solution:
Let's create something similar to merge sort tree, where each node has a multiset of the elements in its range,
we can loop through these values. Building time complexity is O(nlog2n). because we add each element logn
times with time complexity O(logn), because multiset. Now to the queries. When we are supposed to change some element,
we go through the segment tree and remove it from each node that contains it and add its new value instead.
This is also in O(log2n) because we add to logn nodes at most, each with time complexity O(logn) because multiset.
Now for the other type of queries, we do similar to the previous problem. If a node is outside the query range we return INF.
If a node is entirely inside the query range we return the lower bound in this node's multiset. Else we want the minimum
of the answer of the node's right child and left child answers. Time complexity of this queries is O(log2n)
because we go through logn nodes at worst case each with time complexity O(logn) because of binary search (lower bound function).
Time compleixty overall: O((q+n)log2n).

**/

// Code: Merge Sort Tree
// Time Complexity O((q+n)log2n)

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;

int n, q, a[maxn];
multiset<int> tree[4 * maxn];

void build(int node, int start, int end) {
  if (start == end) {
    tree[node].insert(a[start]);
    return;
  }
  int mid = (start + end)/2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  for (int i = start; i <= end; ++i) tree[node].insert(a[i]);
  return;
}

void update(int node, int start, int end, int index, int val) {
  if (start == end) {
    tree[node].erase(a[index]);
    tree[node].insert(val);
    return;
  }
  int mid = (start + end)/2;
  if (index <= mid) update(node * 2, start, mid, index, val);
  else update(node * 2 + 1, mid + 1, end, index, val);
  tree[node].erase(a[index]);
  tree[node].insert(val);
  return;
}

int query(int node, int start, int end, int l, int r, int val) {
  if (start > r || end < l) return 0;
  if (start >= l && end <= r) {
    auto it = tree[node].lower_bound(val);
    if (it == tree[node].end()) return INT_MAX;
  }
  int mid = (start + end)/2;
  return min(query(node * 2, start, mid, l, r, val), query(node * 2 + 1, mid + 1, end, l, r, val));
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, 1, n);
  cin >> q;
  while (q--) {
    bool t;
    cin >> t;
    if (!t) {
      int index, val;
      cin >> index >> val;
      update(1, 1, n, index, val);
      a[index] = val;
    }
    else {
      int l, r, x;
      cin >> l >> r >> x;
      int ans = query(1, 1, n, l, r, x);
      if (ans == INT_MAX) cout << -1 << '\n';
      else cout << ans << '\n';
    }
  }
  return 0;
}