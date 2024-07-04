#include <bits/stdc++.h>

using namespace std;

#define int long long

/**
 * Description: Kosaraju Algorithm for Strongly Connected Component
 * Time Complexity: O(V + E)
 * Space complexity: O(2 * V)
 * Source: https://usaco.guide/adv/SCC?lang=cpp#problems
**/

const int maxn = 2e5 + 5;

int n, m, visited[maxn], ind[maxn];
vector<int> graph[maxn], graph_trans[maxn], s;

void dfs(int node, int pass, int num) {
  visited[node] = 1;
  vector<int> g = (pass == 1 ? graph[node] : graph_trans[node]);
  for (auto& edge: g) {
    if (!visited[edge]) dfs(edge, pass, num);
  }
  s.push_back(node);
  if (pass == 2) ind[node] = num;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph_trans[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) dfs(i, 1, 0);
  }
  memset(visited, 0, sizeof(visited));
  int components = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (!visited[s[i]]) {
      ++components;
      dfs(s[i], 2, components);
    }
  }
  cout << components << '\n';
  for (int i = 1; i <= n; ++i) cout << ind[i] << " \n"[i == n];
  return 0;
}
