#include <bits/stdc++.h>

using namespace std;

// using bellman ford algorithm

const int inf = (int)1e9 + 7;

struct Edge {
  int a, b, cost;
};

int n, m;
vector<Edge> edges;

void finding_negative_cycle() {
  vector<int> d(n);
  vector<int> p(n, -1);
  int x;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (Edge e: edges) {
      if (d[e.a] + e.cost < d[e.b]) {
        d[e.b] = d[e.a] + e.cost;
        p[e.b] = e.a;
        x = e.b;
      }
    }
  }
  if (x == -1) {
    cout << "No negative cycle found\n";
  }
  else {
    for (int i = 0; i < n; ++i) {
      x = p[x];
    }
    vector<int> cycle;
    for (int v = x; ; v = p[v]) {
      cycle.push_back(v);
      if (v == x && (int)cycle.size() > 1) {
        break;
      }
    }
    reverse(cycle.begin(), cycle.end());
    cout << "Negative cycle: ";
    for (auto& v: cycle) {
      cout << v << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  finding_negative_cycle();
  return 0;
}