#include <bits/stdc++.h>

using namespace std;

// Single Source Shortest Path Dijkstra Algorithm
// Space Complexity O(n)
// Time Complexity O(m log n)
const int maxn = (int)1e5 + 5;
const long long inf = 1e18;

vector<pair<int, int>> adj[maxn];
long long d[maxn], parent[maxn];
int n, m;

void dijkstra(int node) {
  for (int i = 1; i <= n; ++i) {
    d[i] = inf;
    parent[i] = -1;
  }
  d[node] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, node});
  while (!q.empty()) {
    int v = q.top().second;
    int d_v = q.top().first;
    q.pop();
    if (d_v != d[v]) {
      continue;
    }
    for (auto& edges: adj[v]) {
      int adj_node = edges.first;
      int edge_cost = edges.second;
      if (d[v] + edge_cost < d[adj_node]) {
        d[adj_node] = d[v] + edge_cost;
        parent[adj_node] = v;
        q.push({d[adj_node], adj_node});
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