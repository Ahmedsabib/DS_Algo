#include <bits/stdc++.h>

using namespace std;

#define int long long

// Longest Increasing Subsequence (LIS)

// Memoization Method(Bottom Up Approach)
// Time Complexity - O(N * N)
// Space Complexity - O(N)

const int maxn = 1e5 + 5;

int dp[maxn];

int lis(int ind, vector<int> &a) {
  if (dp[ind] != -1) return dp[ind];
  dp[ind] = 1; // single element is also a lis
  for (int i = 0; i < ind; ++i) {
    if (a[ind] > a[i]) {
      dp[ind] = max(dp[ind], 1 + lis(i, a));
    }
  }
  return dp[ind];
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << lis(n - 1, a) << '\n';
  return 0;
}