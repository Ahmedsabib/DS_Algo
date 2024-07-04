#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1e5 + 5;
 
int n, m, cycle_start, cycle_end;
vector<int> graph[maxn], color, parent;
 
bool cycle_found(int node) {
  color[node] = 1;
  for (auto& edges: graph[node]) {
    if (color[edges] == 0) {
      parent[edges] = node;
      if (cycle_found(edges)) {
        return true;
      }
    }
    else if (color[edges] == 1) {
      cycle_end = node;
      cycle_start = edges;
      return true;
    }
  }
  color[node] = 2;
  return false;
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  color.assign(n + 1, 0);
  parent.assign(n + 1, -1);
  cycle_start = -1;
  for (int i = 1; i <= n; ++i) {
    if (color[i] == 0 && cycle_found(i)) {
      break;
    }
  }
  if (cycle_start == -1) {
    cout << "IMPOSSIBLE\n";
  }
  else {
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
      cycle.push_back(v);
    }
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    cout << (int)cycle.size() << '\n';
    for (auto& x: cycle) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}