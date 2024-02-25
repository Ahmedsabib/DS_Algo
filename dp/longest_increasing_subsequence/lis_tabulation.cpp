#include <bits/stdc++.h>

using namespace std;

#define int long long

// Longest Increasing Subsequence (LIS)

// Tabulation Method(Bottom Up Approach)
// Time Complexity - O(N * N)
// Space Complexity - O(N)

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> dp(n, 1);
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i] > a[j]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}