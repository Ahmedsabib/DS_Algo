#include <bits/stdc++.h>

using namespace std;

const int inf = (int)1e9 + 7;

// Single-source shortest paths

// Bellman-Ford Algorithm
// Not ideal, Dijkstra is better because of it's O((n + m) log m)
// Better than Dijkstra if there are negative weights, edges and cycles

// Time Complexity O(nm)
// Space Complexity O(n)

int n, m;
// takes three elements in the edges
vector<vector<int>> edge;

void bellman_ford(int node) {
  // firstly, every distance is infinity
  vector<int> dist(n, inf);
  // source nodes distance to itself is 0
  dist[node] = 0;
  // checking for the shortest path distance
  for (int i = 0; i < n - 1; ++i) {
    for (auto& x: edge) {
      int u, v, w;
      u = x[0];
      v = x[1];
      w = x[2];
      dist[v] = min(dist[v], w + dist[u]);
    }
  }
  int ok = 0;
  // checking for negative cycles
  for (int i = 0; i < n - 1; ++i) {
    for (auto& x: edge) {
      long long u, v, w;
      u = x[0];
      v = x[1];
      w = x[2];
      if (dist[u] != inf && dist[u] + w < dist[v]) {
        ok = 1;
        break;
      }
    }
    if (ok) {
      break;
    }
  }
  if (ok) {
    cout << "Negative Cycle Found\n";
  }
  else {
    for (int i = 1; i <= n; ++i) {
      cout << dist[i] << ' ';
    }
    cout << '\n';
  }
  // if there is a negative cycle, then the shortest path cannot be found
  // else print the answer
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.push_back({u, v, w});
  }
  int src = 1;
  bellman_ford(src);
  return 0;
}