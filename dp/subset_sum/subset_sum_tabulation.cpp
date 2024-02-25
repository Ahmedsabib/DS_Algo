#include <bits/stdc++.h>

using namespace std;

#define int long long

// Subset Sum (Tabulation)
// Time Complexity - O(n * target)
// Space Complexity - O(n * target)

const int maxn = 1e2 + 5;
const int maxm = 1e5 + 5;

int nums[maxn];
int dp[maxn][maxm];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> nums[i];
  // 1. base case
  dp[0][0] = 1;
  for (int i = 1; i <= m; ++i) dp[0][i] = 0;
  for (int i = 1; i <= n; ++i) dp[i][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int target = 1; target <= m; ++target) {
      int ans1 = dp[i - 1][target];
      if (target < nums[i]) {
        dp[i][target] = ans1;
      }
      else {
        int ans2 = dp[i - 1][target - nums[i]];
        dp[i][target] = ans1 || ans2;
      }
    }
  }
  cout << dp[n][m] << '\n';
  return 0;
}