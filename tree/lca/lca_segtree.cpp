#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;

vector<int> graph[maxn];

/**
 * LCA (Lowest Common Ancestors)
 * Time Complexity: Preprocessing O(N) && Query O(log N)
 * Resource: https://cp-algorithms.com/graph/lca.html
 * Process: To answer a query we just need to find the vertex with smallest height in the array euler
 * Using Eulers Tour + Segment Tree
 * Problem link: https://cses.fi/problemset/task/1135
**/

template<class T>
struct LCA {
  vector<T> euler, starting, segtree;
  int n, m, timer = 0;

  LCA(int len, int node, int parent) {
    n = len;
    starting.resize(n);
    euler.reserve(n * 2);
    eulers_tour(node, parent);
    m = timer;
    segtree.resize(n * 4);
    build(1, 0, m - 1);
  }

  void eulers_tour(int node, int parent) {
    starting[node] = timer;
    euler[timer++] = node;
    for (auto& edges: graph[node]) {
      if (edges != parent) {
        eulers_tour(edges, node);
        euler[timer++] = node;
      }
    }
  }

  T combine(T x, T y) {
    if (x == -1) return y;
    if (y == -1) return x;
    return (starting[x] < starting[y] ? x : y);
  }

  // Build the segment tree: run build() after dfs
  void build(T node, T l, T r) {
    if (l == r) segtree[node] = euler[l];
    else {
      T mid = (l + r)/2;
      build(node * 2, l, mid);
      build(node * 2 + 1, mid + 1, r);
      segtree[node] = combine(segtree[node * 2], segtree[node * 2 + 1]);
    }
  }

  T query(int node, int a, int b, int l, int r) {
    if (l > b || r < a) return -1;
    if (l >= a && r <= b) return segtree[node];
    int mid = (l + r)/2;
    return combine(query(node * 2, a, b, l, mid), query(node * 2 + 1, a, b, mid + 1, r));
  }

  T lca(T x, T y) {
    T left = starting[x], right = starting[y];
    if (left > right) swap(left, right);
    return query(1, left, right, 0, m - 1);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    --x;
    graph[x].push_back(i + 1);
  }
  LCA<int> lca(n, 0, -1);
  while (q--) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    cout << lca.lca(a, b) + 1 << '\n';
  }
  return 0;
}
