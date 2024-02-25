#include <bits/stdc++.h>

using namespace std;

#define int long long

// Bitmask DP
// Time Complexity - O((2^n) * (n * n))
// Space Complexity - O((2^n) * (n))

const int maxn = 20;

int n, a[maxn][maxn];
int dp[(1 << 15) + 2];

int set_bit(int x, int pos) {
  return x = x | (1 << pos);
}

int reset_bit(int x, int pos) {
  return x = x & ~(1 << pos);
}

int check_bit(int x, int pos) {
  return (x & (1 << pos));
}

int bitmask_dp(int mask) {
  if (mask == (1 << n) - 1) {
    return 0;
  }
  if (dp[mask] != -1) {
    return dp[mask];
  }
  int mini = (1 << 28);
  for (int i = 0; i < n; ++i) {
    if (check_bit(mask, i) == 0) {
      int price = a[i][i];
      for (int j = 0; j < n; ++j) {
        if (i != j && check_bit(mask, j) != 0) {
          price += a[i][j];
        }
      }
      int res = price + bitmask_dp(set_bit(mask, i));
      mini = min(mini, res);
    }
  }
  return dp[mask] = mini;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << bitmask_dp(0) << '\n';
  return 0;
}

/**

Test cases

Input
2
10 10
90 90

Output
110

**/