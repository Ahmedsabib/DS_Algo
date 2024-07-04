#include <bits/stdc++.h>

using namespace std;

#define int long long

// How many N length numbers are there which has every digit at
// least once? No leading zeros are allowed

// Bitmask DP
// Time Complexity O((2 ^ 10) * 1000)
// Space Complexity O((2 ^ 10) * 1000)

int n, dp[1000][(1 << 10) + 2];

int check(int mask) {
  return (mask & ((1 << 10) - 1));
}

int bitmask_dp(int pos, int mask) {
  if (pos >= n) return check(mask);
  if (dp[pos][mask] != -1) return dp[pos][mask];
  int low = 0, res = 0;
  if (pos == 0) low = 1;
  for (int i = low; i < 10; ++i) {
    int val = bitmask_dp(pos + 1, mask | (1 << pos));
    res += val;
  }
  dp[pos][mask] = res;
  return dp[pos][mask];
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  memset(dp, -1, sizeof(dp));
  cout << bitmask_dp(0, 0) << '\n';
  return 0;
}