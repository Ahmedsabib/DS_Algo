#include <bits/stdc++.h>

using namespace std;

// Single Source Shortest Path Dijkstra Algorithm
// Space Complexity O(n)
// Time Complexity O(n * n)
const int maxn = (int)1e5 + 5;
const long long inf = 1e18;

vector<pair<int, int>> adj[maxn];
int d[maxn], visited[maxn], parent[maxn];
int n, m;

void dijkstra(int node) {
  for (int i = 1; i <= n; ++i) {
    d[i] = inf;
    parent[i] = -1;
  }
  d[node] = 0;
  for (int i = 0; i < n; ++i) {
    int selected_node = -1;
    for (int j = 1; j <= n; ++j) {
      if (visited[j] == 1) {
        continue;
      }
      if (selected_node == -1 || d[selected_node] > d[j]) {
        selected_node = j;
      }
    }
    if (d[selected_node] == inf) {
      break;
    }
    visited[selected_node] = 1;
    for (auto& edges: adj[selected_node]) {
      int adj_node = edges.first;
      int edge_cost = edges.second;
      if (d[selected_node] + edge_cost < d[adj_node]) {
        d[adj_node] = d[selected_node] + edge_cost;
        parent[adj_node] = selected_node;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  int source = 1;
  dijkstra(source);
  for (int i = 1; i <= n; ++i) {
    cout << d[i] << ' ';
  }
  cout << '\n';
  return 0;
}