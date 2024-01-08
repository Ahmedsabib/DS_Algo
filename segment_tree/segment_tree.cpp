#include <bits/stdc++.h>

using namespace std;

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
  if (start > r || end < l) {     // start...end l....r
    return 0;
  }
  if (l <= start && end <= r) {   // l..start end...r
    return tree[node];
  }
  // start.. l end.... r or l... start r... end
  int mid = (start + end)/2;
  int q1 = query(2 * node, start, mid, l, r);
  int q2 = query(2 * node + 1, mid + 1, end, l, r);
  return q1 + q2;
}

void update(int node, int start, int end, int index, int value) {
  if (start == end) {
    a[start] = value;
    tree[node] = value;
    return;
  }
  int mid = (start + end)/2;
  if (index <= mid) {
    update(2 * node, start, mid, index, value);
  }
  else {
    update(2 * node + 1, mid + 1, end, index, value);
  }
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
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
      int ind, val;
      cin >> ind >> val;
      update(1, 0, n - 1, ind, val);
    }
  }
  return 0;
}