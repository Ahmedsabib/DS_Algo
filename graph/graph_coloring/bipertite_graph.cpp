#include <bits/stdc++.h>
 
using namespace std;

// Time complexity - O(N * N)
// Time complexity - O(N)
 
const int maxn = 2e5 + 5;
 
vector<int> graph[maxn];
int visited[maxn], color[maxn];
 
bool bipertite(int node) {
  visited[node] = 1;
  for (auto& edges: graph[node]) {
    if (!visited[edges]) {
      visited[edges] = 1;
      if (color[node] == 1) {
        color[edges] = 2;
      }
      else {
        color[edges] = 1;
      }
      if (!bipertite(edges)) {
        return false;
      }
    }
    else if (color[edges] == color[node]) {
      return false;
    }
  }
  return true;
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int is_bipertite = 1;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      color[i] = 1;
      bool ok = bipertite(i);
      if (!ok) {
        is_bipertite = 0;
        break;
      }
    }
  }
  if (!is_bipertite) {
    cout << "IMPOSSIBLE\n";
  }
  else {
    for (int i = 1; i <= n; ++i) {
      cout << color[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}