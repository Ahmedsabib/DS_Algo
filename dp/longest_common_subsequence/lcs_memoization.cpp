#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 3e3 + 5;

// Longest Common subsequence (LCS)

// Memoization Method(Bottom Up)
// Time Complexity - O(N * M)
// Space Complexity - O(N * M)

int n, m;
string s, t;
int dp[maxn][maxn];

int lcs(int i, int j) {
  // 1. base case
  if (i == n || j == m) return 0;
  // 2. if result is already calculated return it
  if (dp[i][j] != -1) return dp[i][j];
  // 3. calculate result from smaller sub-problems
  if (s[i] == t[j]) {
    int ans = 1 + lcs(i + 1, j + 1);
    dp[i][j] = ans;
    return ans;
  }
  int ans = max(lcs(i + 1, j), lcs(i, j + 1));
  dp[i][j] = ans;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> s >> t;
  n = (int)s.size(), m = (int)t.size();
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i][j] = -1;
    }
  }
  cout << lcs(0, 0) << '\n';
  return 0;
}