#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int maxn = 2e5 + 5;

int n, q;
vector<int> graph[maxn];

/**
 * Lowest Common Ancestors [Using Sparse Table]
 * Time Complexity: Preprocessing O(N log N) && Query O(log N)
 * Source: https://usaco.guide/plat/binary-jump?lang=cpp
 * Problem link: https://cses.fi/problemset/task/1135
**/

template<class T>
struct LCA {
  int n, l;
  vector<vector<T>> upper_level;
  vector<T> depth;

  LCA(int len, int root) {
    n = len;
    depth.resize(n);
    l = ceil(log2(n));
    upper_level.assign(n, vector<int> (l + 1));
    dfs(root);
  }

  void dfs(int node) {
    for (int i = 1; i <= l; ++i) {
      upper_level[node][i] = upper_level[upper_level[node][i - 1]][i - 1];
    }
    for (auto& edges: graph[node]) {
      if (edges != upper_level[node][0]) {
        depth[edges] = depth[upper_level[edges][0] = node] + 1;
        dfs(edges);
      }
    }
  }

  int jump(int x, int d) {
    for (int i = 0; i <= l; ++i) {
      if ((d >> i) & 1) x = upper_level[x][i];
    }
    return x;
  }

  T lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = jump(a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = l; i >= 0; --i) {
      int a_pos = upper_level[a][i];
      int b_pos = upper_level[b][i];
      if (a_pos != b_pos) a = a_pos, b = b_pos;
    }
    return upper_level[a][0];
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> q;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x--; --y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  LCA<int> lca(n, 0);
  while (q--) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    cout << lca.depth[a] + lca.depth[b] - 2 * lca.depth[(lca.lca(a, b))] << '\n';
  }
  return 0;
}
