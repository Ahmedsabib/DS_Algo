#include <bits/stdc++.h>

using namespace std;

#define int long long

// Travelling Salesman Problem

// Bitmask DP

const int maxn = 10;
const int inf = 1e9;

int n, m, a[maxn][maxn];
int dp[maxn][1 << maxn];

int set_bit(int x, int pos) {
  return x | (1 << pos);
}

int check_bit(int x, int pos) {
  return (x & (1 << pos));
}

int bitmask_dp(int pos, int mask) {
  if (mask == (1 << pos) - 1) {
    return a[pos][0];
  }
  if (dp[pos][mask] != -1) {
    return dp[pos][mask];
  }
  int ans = inf;
  for (int i = 0; i < n; ++i) {
    if (a[pos][i] == inf) continue;
    if (check_bit(mask, i) == 0) {
      int res = bitmask_dp(i, set_bit(mask, i)) + a[pos][i];
      ans = min(ans, res);
    }
  }
  return dp[pos][mask] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  memset(a, inf, sizeof(a));
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    a[u][v] = w;
    a[v][w] = w;
  }
  cout << bitmask_dp(0, 0) << '\n';
  return 0;
}