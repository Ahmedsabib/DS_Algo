// ============= DFS ====================
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 7;
// Method 1 (for each loop)
// Time Complexity O(n+m)
// Space Complexity O(n)
// n is the number of vertex and
// m is the number of edges
vector<long long> adj[maxn];
bool visited[maxn];
void dfs(long long node) {
	visited[node] = true;
	cout << node << ' ';
	// using for each loop
	for (auto& edges: adj[node]) {
		if (!visited[edges]) {
			dfs(edges);
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
  for (int i = 1; i <= n; ++i) {
  	if (!visited[i]) {
  		dfs(i);
  	}
  }
  return 0;
}