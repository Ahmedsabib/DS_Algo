#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;

// Segment Tree with Lazy Propagation

int a[maxn], tree[4 * maxn], lazy[4 * maxn];

void build(int node, int start, int end) {
  if (start == end) {
     // Leaf node will have a single element
    tree[node] = a[start];
    return;
  }
  int mid = (start + end)/2;
  // Recurse on the left child
  build(2 * node, start, mid);
   // Recurse on the right child
  build(2 * node + 1, mid + 1, end);
  // Internal node will have the sum of both of its children
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int start, int end, int l, int r, int val) {
  if (lazy[node] != 0) {
    // This node needs to be updated
    tree[node] += (end - start + 1) * lazy[node]; // Update it
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  // Current segment is not within range [l, r]
  if (start > end || start > r || end < l) return;
  if (start >= l && end <= r) {
    // Segment is fully within range
    tree[node] += (end - start + 1) * val;
    if (start != end) {
      // Not leaf node
      lazy[node * 2] += val;
      lazy[node * 2 + 1] += val;
    }
    return;
  }
  int mid = (start + end)/2;
  update(node * 2, start, mid, l, r, val); // Updating left child
  update(node * 2 + 1, mid + 1, end, l, r, val); // Updating right child
  tree[node] = tree[node * 2] + tree[node * 2 + 1]; // Updating root with max value
}

int query(int node, int start, int end, int l, int r) {
  if (start > end || start > r || end < l) return 0; // Out of range
  if (lazy[node] != 0) {
    // This node needs to be updated
    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node]; // Mark child as lazy
      lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
    }
    lazy[node] = 0; // Reset it
  }
  if (start >= l && end <= r) return tree[node]; // Current segment is totally within range [l, r]
  int mid = (start + end)/2;
  int p1 = query(node * 2, start, mid, l, r); // Query left child
  int p2 = query(node * 2 + 1, mid + 1, end, l, r); // Query right child
  return (p1 + p2);
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  build(1, 0, n - 1);
  while (1) {
    int type;
    cin >> type;
    if (type == -1) {
      break;
    }
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      int ans = query(1, 0, n - 1, l, r);
      cout << ans << '\n';
    }
    else if (type == 2) {
      int ind_start, ind_end, val;
      cin >> ind_start >> ind_end >> val;
      update(1, 0, n - 1, ind_start, ind_end, val);
    }
  }  
  return 0;
}