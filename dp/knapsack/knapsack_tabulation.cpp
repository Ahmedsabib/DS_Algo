#include <bits/stdc++.h>

using namespace std;

#define int long long

// Knapsack (Tabulation)
// Time Complexity O(n * w)
// Space Complexity O(n * w)

const int maxn = 102;
const int maxm = 1e5 + 5;

int n, w;
int dp[maxn][maxm];
int wt[maxn], val[maxn];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> w;
  for (int i = 1; i <= n; ++i) {
    cin >> wt[i] >> val[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int cap = 0; cap <= w; ++cap) {
      if (cap < wt[i]) {
        dp[i][cap] = dp[i - 1][cap];
      }
      else {
        dp[i][cap] = max(val[i] + dp[i - 1][cap - wt[i]], dp[i - 1][cap]);
      }
    }
  }
  cout << dp[n][w] << '\n';
  return 0;
}