// ========== BFS ======================
#include <bits/stdc++.h>
using namespace std;
// Time Complexity - O(n + m)
// n is the number of nodes
// m is the number of vertices
const int maxn = 1e5 + 7;
vector<int> adj[maxn];
queue<int> q;
bool visited[maxn];
int distances[maxn];
void bfs(int node) {
  visited[node] = true;
  distances[node] = 0;
  q.push(node);
  while (!q.empty()) {
    int s = q.front();
    q.pop();
    cout << s << '\n';
    // process node s
    for (auto& edges: adj[s]) {
      if (!visited[edges]) {
        visited[edges] = true;
        distances[edges] = distances[s] + 1;
        q.push(edges);
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
  	int u, v;
  	cin >> u >> v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  bfs(1);
  cout << distances[4] << '\n';
  return 0;
}