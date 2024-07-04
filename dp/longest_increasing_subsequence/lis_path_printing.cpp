#include <bits/stdc++.h>

using namespace std;

#define int long long

// Longest Increasing Subsequence (LIS) with Path printing

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
  vector<int> dp(n, 1), p(n, -1), path;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i] > a[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        p[i] = j;
      }
    }
  }
  int ans = dp[0], pos = 0;
  for (int i = 1; i < n; ++i) {
    if (dp[i] > ans) {
      ans = dp[i];
      pos = i;
    }
  }
  while (pos != -1) {
    path.push_back(a[pos]);
    pos = p[pos];
  }
  reverse(path.begin(), path.end());
  for (int i = 0; i < (int)path.size(); ++i) {
    cout << path[i] << ' ';
  }
  cout << '\n';
  return 0;
}