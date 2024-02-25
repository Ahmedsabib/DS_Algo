#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 9;

// Time complexity - O(1)
// Space complexity - O(n)
struct DSU {
  vector<int> par, rnk, sz;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
    }
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c;    //connected components
  }
  // Path compression
  // O(1)
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) {
      return -1;
    }
    else {
      --c;
    }
    if (rnk[i] > rnk[j]) {
      swap(i, j);
    }
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j]) {
      rnk[j]++;
    }
    return j;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  DSU dsu(n);
  vector<pair<int, int>> res;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    if (dsu.find(u) == dsu.find(v)) {
      res.push_back({u, v});
    }
    else {
      dsu.merge(u, v);
    }
  }
  vector<int> temp;
  for (int i = 1; i <= n; ++i) {
    if (dsu.find(i) == i) {
      temp.push_back(i);
    }
  }
  int ans = (int)temp.size() - 1;
  cout << ans << '\n';
  for (int i = 0; i < ans; ++i) {
    cout << res[i].first << ' ' << res[i].second << ' ';
    cout << temp[i] << ' ' << temp[i + 1] << '\n';
  }
  return 0;
}
