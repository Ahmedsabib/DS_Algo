#include <bits/stdc++.h>
 
using namespace std;

// Time Complexity - O(N + M)
// Space Complexity - O(N)
 
const int maxn = 2e5 + 5;

int n, m;
vector<int> graph[maxn];
int visited[maxn];
stack<int> nodes_path;
 
void dfs(int node) {
  visited[node] = 1;
  for (auto& edges: graph[node]) {
    if (!visited[edges]) {
      dfs(edges);
    }
  }
  nodes_path.push(node);
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  while (!nodes_path.empty()) {
    cout << nodes_path.top() << ' ';
    nodes_path.pop();
  }
  cout << '\n';
  return 0;
}