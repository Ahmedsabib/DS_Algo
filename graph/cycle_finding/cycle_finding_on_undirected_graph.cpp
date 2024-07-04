#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)1e5 + 5;

vector<int> graph[maxn], cycle;
int visited[maxn];

int dfs(int node, int p) {
  visited[node] = 1;
  for (auto& edges: graph[node]) {
    cycle.push_back(edges);
    if (!visited[edges]) {
      if (dfs(edges, node)) {
        return 1;
      }
    }
    else if (edges != p) {
      return 1;
    }
    cycle.pop_back();
  }
  return 0;
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
  for (int i = 1; i <= n; ++i) {
    cycle.push_back(i);
    if (!visited[i] && dfs(i, 0)) {
      vector<int> ans = {cycle.back()};
      for (auto j = cycle.rbegin() + 1; j != cycle.rend(); ++j) {
        ans.push_back(*j);
        if (*j == *cycle.rbegin()) {
          break;
        }
      }
      cout << (int)ans.size() << '\n';
      for (auto& x: ans) {
        cout << x << ' ';
      }
      cout << '\n';
      return 0;
    }
    cycle.pop_back();
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}