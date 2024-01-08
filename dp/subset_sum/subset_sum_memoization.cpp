#include <bits/stdc++.h>

using namespace std;

#define int long long

// Subset Sum (Memoization)
// Time Complexity - O(n * target)
// Space Complexity - O(n * target)

const int maxn = 1e2 + 5;
const int maxm = 1e5 + 5;

int nums[maxn];
int dp[maxn][maxm];

int subset_sum(int n, int target) {
  // 1. base case
  if (n == 0) {
    if (target == 0) return 1;
    return 0;
  }
  // 2. if result is already calculated, return it
  if (dp[n][target] != -1) {
    return dp[n][target];
  }
  // 3. calculate result from smaller states
  int ans1 = subset_sum(n - 1, target);
  if (target < nums[n]) {
    dp[n][target] = ans1;
    return ans1;
  }
  int ans2 = subset_sum(n - 1, target - nums[n]);
  int ans = ans1 || ans2;
  dp[n][target] = ans;
  return ans;
  // dp[n][target] = 1;
  // return 1;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, target;
  cin >> n >> target;
  for (int i = 1; i <= n; ++i) cin >> nums[i];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= target; ++j) {
      dp[i][j] = -1;
    }
  }
  cout << subset_sum(n, target) << '\n';
  return 0;
}