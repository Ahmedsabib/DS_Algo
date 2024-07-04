#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

// All-pairs shortest paths

// Floyd-Warshall Algorithm
// This technique can be applied if : n <= 500

// For positive weight
// Time Complexity O(n^3)
// Space Complexity O(n^2)

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  long long n, m, q;
  cin >> n >> m >> q;
  long long graph[n + 1][n + 1];
  // First, the algorithm initializes distance using 
  // the adjacency matrix adj of the graph
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) {
        graph[i][j] = 0;
      }
      else {
        graph[i][j] = inf;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    long long u, v, w;
    cin >> u >> v >> w;
    graph[u][v] = min(graph[u][v], w);
    graph[v][u] = min(graph[v][u], w);
  }
  // Then the shortest distances can be found as follows
  // Remeber the Sequence of looping -> k - i - j
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }
  while (q--) {
    long long a, b;
    cin >> a >> b;
    long long ans = graph[a][b];
    if (ans == inf) {
      cout << "-1\n";
    }
    else {
      cout << ans << '\n';
    }
  }
  return 0;
}