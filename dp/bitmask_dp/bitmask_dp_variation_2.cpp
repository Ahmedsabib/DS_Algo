#include <bits/stdc++.h>

using namespace std;

#define int long long

// Given a string S(only digits) and an integer D,
// how many permutations of S is divisible by D
// Assume that, length of S <= 10, 1 <= D <= 1000
// All digit of S are unique

// Bitmask DP
// Time Complexity - O((2^10) * 1005)
// Space Complexity - O((2^10) * 1005)

string s;
int d, dp[(1 << 10) + 2][1005];

int bitmask_dp(int mask, int mod) {
  int pos = __builtin_popcount(mask);
  if (pos == (int)s.size()) return (mod == 0);
  if (dp[mask][mod] != -1) return dp[mask][mod];
  int res = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (((1 << i) & mask)) continue;
    int val = bitmask_dp(mask | (1 << i), (mod * 10 + s[i] - '0')%d);
    res += val;
  }
  dp[mask][mod] = res;
  return dp[mask][mod];
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> s >> d;
  memset(dp, -1, sizeof(dp));
  cout << bitmask_dp(0, 0) << '\n';
  return 0;
}