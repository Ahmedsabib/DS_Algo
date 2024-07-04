#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 9;

// Kruskal (Minimum Spanning Tree)
// Time complexity - O(E log E)

struct DSU {
  vector<int> par, rnk, size; int c;
  DSU(int n) : par(n + 1), rnk(n + 1,0), size(n + 1,1), c(n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
  bool same(int i, int j) { return find(i) == find(j); }
  int get_size(int i) { return size[find(i)]; }
  int count() { return c; } //connected components
  // Path compression
  // O(1)
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1; else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j; size[j] += size[i];
    if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }
  sort(edges.begin(), edges.end());
  long long ans = 0, cnt_edges = 0;
  DSU dsu(n);
  for (auto& x: edges) {
    int u = x[1], v = x[2], w = x[0];
    if (dsu.same(u, v)) {
      continue;
    }
    ans += w;
    dsu.merge(u, v);
    ++cnt_edges;
  }
  if (ans >= 0 && cnt_edges == n - 1) {
    cout << ans << '\n';
  }
  else {
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}
