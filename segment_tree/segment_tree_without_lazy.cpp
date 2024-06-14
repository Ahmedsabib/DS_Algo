#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = (int)1e5 + 5;

int a[maxn], tree[4 * maxn];

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = a[start];
    return;
  }
  int mid = (start + end)/2;
  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r) {
  if (start > r || l > end) return 0;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end)/2;
  int p1 = query(2 * node, start, mid, l, r);
  int p2 = query(2 * node + 1, mid + 1, end, l, r);
  return p1 + p2 + tree[node];
}

void update(int node, int start, int end, int l, int r, int v) {
  if (start > r || l > end) return;
  if (start >= l && end <= r) {
    tree[node] += v;
    return;
  }
  int mid = (start + end)/2;
  update(2 * node, start, mid, l, r, v);
  update(2 * node + 1, mid + 1, end, l, r, v);
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  build(1, 0, n - 1);
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      update(1, 0, n - 1, l, r - 1, v);
    }
    else if (type == 2) {
      int ind;
      cin >> ind;
      cout << query(1, 0, n - 1, ind, ind) << '\n';
    }
  }
  return 0;
}
