#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 3e5 + 5;

int n, m;
int a[maxn];
pair<int, int> tree[4 * maxn];

void build(int node, int start, int end) {
  if (start == end) {
    tree[node].first = a[start];
    tree[node].second = 1;
    return;
  }
  int mid = (start + end)/2;
  build(2 * node, start, mid); 
  build(2 * node + 1, mid + 1, end); 
  if (tree[2 * node].first > tree[2 * node + 1].first) {
    tree[node].first = tree[2 * node].first;
    tree[node].second = tree[2 * node].second;
  }
  else if (tree[2 * node].first < tree[2 * node + 1].first) {
    tree[node].first = tree[2 * node + 1].first;
    tree[node].second = tree[2 * node + 1].second;
  }
  else {
    tree[node].first = tree[2 * node + 1].first;
    tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
  }
}

pair<int, int> query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) return {INT_MIN, 0};
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end)/2;
  pair<int, int> q1 = query(2 * node, start, mid, l, r);
  pair<int, int> q2 = query(2 * node + 1, mid + 1, end, l, r);
  pair<int, int> q;
  if (q1.first > q2.first) q = q1; 
  else if (q1.first < q2.first) q = q2;
  else {
    q.first = q1.first;
    q.second = q1.second + q2.second;
  }
  return q;
}

void update(int node, int start, int end, int index, int value) {
  if (start == end) {
    a[start] = value;
    tree[node].first = value;
    tree[node].second = 1;
    return;
  }
  int mid = (start + end)/2;
  if (index <= mid) update(2 * node, start, mid, index, value);
  else update(2 * node + 1, mid + 1, end, index, value);
  if (tree[2 * node].first > tree[2 * node + 1].first) {
    tree[node].first = tree[2 * node].first;
    tree[node].second = tree[2 * node].second;
  }
  else if (tree[2 * node].first < tree[2 * node + 1].first) {
    tree[node].first = tree[2 * node + 1].first;
    tree[node].second = tree[2 * node + 1].second;
  }
  else {
    tree[node].first = tree[2 * node + 1].first;
    tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  build(1, 0, n - 1);
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int ind, val;
      cin >> ind >> val;
      ind--;
      update(1, 0, n - 1, ind, val);
    }
    else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      pair<int, int> ans = query(1, 0, n - 1, l, r);
      cout << ans.first << ' ' << ans.second << '\n';
    }
  }
  return 0;
}