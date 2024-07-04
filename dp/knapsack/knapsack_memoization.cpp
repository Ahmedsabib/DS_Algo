#include <bits/stdc++.h>

using namespace std;

#define int long long

// Knapsack (Memoization)
// Time Complexity O(n * w)
// Space Complexity O(n * w)

const int maxn = 102;
const int maxm = 1e5 + 5;

int dp[maxn][maxm];
int wt[maxn], val[maxn];

int knapsack(int n, int cap) {
  // 1. base case
  if (n == 0) return 0;
  // 2. If the result is already calculated for this state, return it
  if (dp[n][cap] != 1) return dp[n][cap];
  if (cap < wt[n]) {
    int ans = knapsack(n - 1, cap);
    dp[n][cap] = ans;
    return ans; 
  }
  int ans1 = val[n] + knapsack(n - 1, cap - wt[n]);
  int ans2 = knapsack(n - 1, cap);
  int ans = max(ans1, ans2);
  dp[n][cap] = ans;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, cap;
  cin >> n >> cap;
  for (int i = 1; i <= n; ++i) {
    cin >> wt[i] >> val[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= cap; ++j) {
      dp[i][j] = -1;
    }
  }
  cout << knapsack(n, cap) << '\n';
  return 0;
}