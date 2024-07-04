#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 3e3 + 5;

// Longest Common subsequence (LCS)

// Tabulation Method(Bottom Up)
// Time Complexity - O(N * M)
// Space Complexity - O(N * M)

int n, m;
string s, t;
int dp[maxn][maxn];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> s >> t;
  n = (int)s.size(), m = (int)t.size();
  // 1. base case
  for (int i = 0; i <= n; ++i) dp[i][m] = 0;
  for (int i = 0; i <= m; ++i) dp[n][i] = 0;
  // 2. loop over the states
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      // 2.1. Calculate answer from sub-problems
      if (s[i] == t[j]) {
          dp[i][j] = 1 + dp[i + 1][j + 1];
      }
      else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  cout << dp[0][0] << '\n';
  return 0;
}