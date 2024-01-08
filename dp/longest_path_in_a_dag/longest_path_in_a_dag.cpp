#include <bits/stdc++.h>

using namespace std;

#define int long long

// Longest Path in a DAG

const int maxn = (int)1e5 + 5;

int dp[maxn];
int root, target_node;
vector<int> graph[maxn];

int max_distance(int node) {
  // 1. base case
  if (node == root) return 0;
  // 2. return result if already calculated
  if (dp[node] != -1) return dp[node];
  // 3. calculate result from smaller nodes
  int ans = 0;
  for (auto& par: graph[node]) {
    int par_dist = max_distance(par);
    ans = max(ans, par_dist);
  }
  ++ans;
  dp[node] = ans;
  return dp[node];
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) dp[i] = -1;
  cin >> root >> target_node;
  cout << max_distance(target_node) << '\n';
  return 0;
}