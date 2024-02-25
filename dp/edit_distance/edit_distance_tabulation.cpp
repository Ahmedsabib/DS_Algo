#include <bits/stdc++.h>

using namespace std;

#define int long long

// Edit Distance (Tabulation)
// Time Complexity O(n * m)
// Space Complexity O(n * m)

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  string s, t;
  cin >> s >> t;
  int n = (int)s.size();
  int m = (int)t.size();
  vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
  for (int i = 0; i <= n; ++i) dp[i][0] = i;
  for (int i = 0; i <= m; ++i) dp[0][i] = i;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
      }
    }
  }
  cout << dp[n][m] << '\n';
  return 0;
}